#include "header.h"
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

bool junct = false;
int junct_count = 0;
int directions[9] = {RIGHT, LEFT, FORWARD, LEFT, LEFT, LEFT, RIGHT, RIGHT, LEFT};

void decide(int sensors) {
sensors = sensors%16; // makes sure only the sensors are read
cout << sensors << endl;
const float Kp = 60;
float Kd = 40;
const float Ki = 0;	// proportional, integral and derivative constants - need testing
static int prev = sensors; // holds the previous position of the line follower
if (prev == 15) Kd = 1;
static float I = 0; // initialise integral control
static int olderror = 0; // initialise proportional control
int errorterm = 0;
if (sensors >= 8) errorterm = errorterm - 1;
if ((sensors%8-sensors%4-sensors%2) == 4) errorterm = errorterm -1;
if ((sensors%4-sensors%2) == 2) {errorterm = errorterm + 1;}
if ((sensors%2) == 1) {errorterm = errorterm + 1;}
if (sensors == 1) errorterm = 3;
if (sensors == 8) errorterm = -3;
if (sensors ==0) {
	if (prev == 1) errorterm = 4;
	else errorterm = -4;
}
float P = Kp*errorterm;
I = I + errorterm*Ki;
float D = (errorterm - olderror)*Kd;
int control = P+I+D;
cout << control << endl;
bool direction = RIGHT;
if (control < 0) {
	control = 0-control;
	direction = LEFT;
}
if (sensors == 0) control = 0;
if (control > MAXSPEED) control = MAXSPEED;
olderror = errorterm;
if (sensors == 15) olderror = 0;
cout << control << endl;
veer(direction, control);
if (sensors != 0) prev = sensors;

switch (sensors) {

case 8*0+4*0+2*0+1*0: // no line detected
//stop();
cout << "Lost the line" << endl;
return;
decide(prev);
break;

/*
case (8*1+4*1+2*0+1*1): case (8*1+4*0+2*1+1*1): case (8*1+4*0+2*1+1*0
): case (8*0+4*1+2*1+1*0): case (8*0+4*1+2*0+1*0): case (8*0+4*0+2*1+
1*0): cout << "wtf?" << endl; decide(prev); break; //Some of these depend on how far apart the sesnors are on whether they are WTF or not. Needs Examining.
*/
case 8*1+4*1+2*1+1*1: // at a junct2ion
cout << "Junction detected!" << endl;
junct = true;
Crossroads(junct_count);
junct_count++;
// insert pathfinding code here
prev = sensors;
break;

default:
break;
}
}

void Crossroads(int junct_count) {
	int dir = directions[junct_count];
	int linereps = 0;
	int input = 8*1+4*1+2*1+1*1;
		if (dir==LEFT || dir==RIGHT) {
				straightRun(MAXSPEED*THROTTLE);
				delay(400);
				fastVeer(dir, MAXSPEED);
				delay(500);
				input = readLF()%16;
				cout << "hi" << endl;
			while (linereps < 8) {
				swivel(dir, 0.6*MAXSPEED);
				delay(28);
				input = readLF()%16;
				if (input != 0 && input != 15) linereps++;
				else linereps = 0;
				cout << "loopy" << endl;
			}				
		}
		else 
		while (input == 15) {
		straightRun(MAXSPEED*THROTTLE);
		delay(10);
		input = readLF()%16;
	}
	junct = false;
	decide(input);	
}
