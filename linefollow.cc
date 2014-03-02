#include "header.h"
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

bool junct = false;
int junct_count = 0;
int directions[9] = {RIGHT, LEFT, FORWARD, LEFT, LEFT, LEFT, RIGHT, RIGHT, LEFT};

void decide(int sensors) {
int sensors = sensors & 0b1111; // makes sure only the sensors are read
const float Kp = 1
const float Kd = 0
const float Ki = 0	// proportional, integral and derivative constants - need testing
static int prev = sensors; // holds the previous position of the line follower
static float I = 0; // initialise integral control
static float olderror = 0; // initialise proportional control
int errorterm = 0;
if (sensors & 0b1000 == 0) errorterm = errorterm - 2;
if (sensors & 0b0100 == 0) errorterm--;
if (sensors & 0b0010 == 0) errorterm++;
if (sensors & 0b0001 == 0) errorterm = errorterm + 2;
float P = Kp*errorterm;
I = I + errorterm*Ki;
float D = (errorterm - olderror)*Kd;
int control = P+I+D;
bool direction = LEFT;
if (control < 0) {
	control = -control;
	direction = RIGHT;
}
if (control > MAXSPEED) control = MAXSPEED;
veer(direction, control);
switch (sensors) {
/*//Need to check which sensors are meant to be on the line, and whetherline is on or off.
case 8*1+4*0+2*0+1*1: // central sensors detect a line
straightRun(MAXSPEED);
prev = sensors;
break;
*/

case 8*1+4*1+2*1+1*1: // no line detected
stop();
cout << "Lost the line" << endl;
//decide(prev);
break;
/*

case 8*1+4*1+2*1+1*0: // rightmost sensor only
veer(RIGHT, MAXSPEED);
prev = sensors;
break;
*/
case (8*1+4*1+2*0+1*1): case (8*1+4*0+2*1+1*1): case (8*1+4*0+2*1+1*0
): case (8*0+4*1+2*1+1*0): case (8*0+4*1+2*0+1*0): case (8*0+4*0+2*1+
1*0): cout << "wtf?" << endl; decide(prev); break; //Some of these depend on how far apart the sesnors are on whether they are WTF or not. Needs Examining.
/*
case 8*1+4*1+2*0+1*0: // 2 sensors on the right - probably veering off the line
veer(RIGHT, 51);
prev = sensors;
break;

case 8*1+4*0+2*0+1*0: // 3 sensors on the right - probably at an angle
swivel(RIGHT, 51);
prev = sensors;
break;

case 8*0+4*1+2*1+1*1: // leftmost sensor only
veer(LEFT, MAXSPEED);
prev = sensors;
break;

case 8*0+4*0+2*1+1*1: // 2 sensors on left
veer(LEFT, 51);
prev = sensors;
break;

case 8*0+4*0+2*0+1*1: // 3 sensors on left - probs at an angle
swivel(LEFT, 51);
prev = sensors;
break;
*/

case 8*0+4*0+2*0+1*0: // at a junction
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
	int input = 8*1+4*1+2*1+1*1;
	while (input == 15 || input == 0) {
		if (dir==LEFT || dir==RIGHT) veer(dir, MAXSPEED);
		else straightRun(MAXSPEED);
		delay(1000);
		int input = readLF();
	}
	junct = false;
	decide(input);	
}
