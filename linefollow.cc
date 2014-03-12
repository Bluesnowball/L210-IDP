#include "header.h"

bool pickup = true;
//unsigned int junct_count = 0;
//int directions[10] = {FORWARD, RIGHT, RIGHT, PAUSE, SPINBACK, RIGHT, RIGHT, LEFT, PAUSE, STOP};
//int direcs1[5] = {SPINBACK, FORWARD, LEFT, PAUSE, STOP};

stopwatch watch;

void decide(int sensors) {	// line following
int temp=0;
	if (ShiningPath.Indicator >= ShiningPath.Instruct.size()) {
		temp=ShiningPath.Loc[ShiningPath.Indicator];
		ShiningPath = MarcoPolo(Green, !pickup, temp);
		ShiningPath.Indicator = 0;
	}
if ((ShiningPath.Instruct[ShiningPath.Indicator] == SPINBACK || ShiningPath.Instruct[ShiningPath.Indicator] == STOP) && watch.read() == 0){ 
	ShiningPath.Indicator++;
	Crossroads(ShiningPath.Indicator-1);
} 
// makes sure only the sensors are read - bits 0-3
//cout << sensors << endl;
float Kp = 24;
float Kd = 16;
float Ki = 0.09;	// proportional, integral and derivative constants - need testing
static int prev = sensors; // holds the previous position of the line follower
if (prev == 15) Kd = 1;
static float I = 0; // initialise integral control
static int olderror = 0; // initialise proportional control
int errorterm = 0;
/*
if (sensors >= 8) errorterm = errorterm - 1;
if ((sensors%8-sensors%4-sensors%2) == 4) errorterm = errorterm -1;
if ((sensors%4-sensors%2) == 2) {errorterm = errorterm + 1;}
if ((sensors%2) == 1) {errorterm = errorterm + 1;}
*/ 
switch(sensors) {
	case 1:
	errorterm = 3;
	break;
	
	case 2:
	errorterm = 1;
	break;
	
	case 3:
	errorterm = 2;
	break;
	
	case 4:
	errorterm = -1;
	break;
	
	case 8:
	errorterm = -3;
	break;
	
	case 12:
	errorterm = -2;
	break;
	
	case 0: // lost the line
	errorterm = Lost(prev);
	break;
	
	case 15: // at a junction
	cout << "Junction detected!" << endl;
	if(ShiningPath.Instruct[ShiningPath.Indicator] != FORWARD) I=0;
	Crossroads(ShiningPath.Indicator);
	ShiningPath.Indicator++;
	prev = sensors;
	errorterm = 0;
	break;
	
	default:
	break;
}
float P = Kp*errorterm;
I = I + errorterm*Ki;
float D = (errorterm - olderror)*Kd;
int control = P+I+D;				// implements PID control		
bool direction = RIGHT;
if (control < 0) {
	control = 0-control;
	direction = LEFT;
}
if (sensors == 0) control = 0;
if (control > MAXSPEED*THROTTLE) control = MAXSPEED*THROTTLE;
olderror = errorterm;	// avoids messing up derivative control at junctions
veer(direction, control);
if (sensors != 0) prev = sensors;		// updates last position unless it's lost
}

void Crossroads(int junctcount) {
	int dir = ShiningPath.Instruct[junctcount];
	int linereps = 0;
	int input = 8*1+4*1+2*1+1*1;
	bool line1 = false;
		if (dir == STOP) {
			stop();
			delay(100000);
		}
		if (dir == PAUSE) {
			
			watch.start();
			while (watch.read() < 650) {
				Crossroads(0);
				Advance();
			}
			watch.stop();
			stop();
			delay(1000);
			Manipulate(pickup);
			if (pickup == true) {
			int shirt = Identify();
			cout << shirt << endl;
			}
			pickup = !pickup;
		}
		if (dir == SPINBACK) {
				stop();
				straightRun(REVERSE);
				delay(100/THROTTLE);
				swivel(dir, 0.6*MAXSPEED);
				delay(600);
				input = readLF();
				cout << "hi" << endl;
			while (linereps < 8 || line1 == false) {
				swivel(dir, 0.6*MAXSPEED);
				delay(33);
				input = readLF();
				if (input != 0 && input != 15) linereps++;
				else linereps = 0;
				if (linereps == 14 && line1 == false) {
					line1 = true;
					linereps = 0;
				}
				//cout << "loopy" << endl;
			}
		}
		if (dir==LEFT || dir==RIGHT) {
				straightRun(MAXSPEED*THROTTLE);
				delay(300/THROTTLE);
				swivel(dir, MAXSPEED*0.6);
				delay(800);
				input = readLF();
				//cout << "hi" << endl;
			while (linereps < 8) {
				swivel(dir, 0.6*MAXSPEED);
				delay(33);
				input = readLF();
				if (input != 0 && input != 15) linereps++;
				else linereps = 0;
				//cout << "loopy" << endl;
			}				
		}
		else 
		straightRun(MAXSPEED*THROTTLE);
		while (input == 15) {
		input = readLF();
	}
	decide(input);	
}
