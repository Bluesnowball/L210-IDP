#include "header.h"

int junct_count = 0;
int directions[9] = {RIGHT, LEFT, FORWARD, LEFT, LEFT, LEFT, RIGHT, RIGHT, LEFT};

void decide(int sensors) {	// line following
sensors = sensors%16; // makes sure only the sensors are read - bits 0-3
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
switch(sensors) {
	case 1:
	errorterm = 3;
	break;
	
	case 8:
	errorterm = -3;
	break;
	
	case 0: // lost the line
	if (prev == 1) errorterm = 4;
	else errorterm = -4;
	cout << "lost the line" << endl;
	break;
	
	case 15: // at a junction
	cout << "Junction detected!" << endl;
	Crossroads(junct_count);
	junct_count++;
	prev = sensors;
	break;
	
	default:
	break;
}
float P = Kp*errorterm;
I = I + errorterm*Ki;
float D = (errorterm - olderror)*Kd;
int control = P+I+D;				// implements PID control
cout << control << endl;			
bool direction = RIGHT;
if (control < 0) {
	control = 0-control;
	direction = LEFT;
}
if (sensors == 0) control = 0;
if (control > MAXSPEED) control = MAXSPEED;
olderror = errorterm;
if (sensors == 15) olderror = 0;		// avoids messing up derivative control at junctions
veer(direction, control);
if (sensors != 0) prev = sensors;		// updates last position unless it's lost
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
	decide(input);	
}
