#include "header.h"

bool supervision = false;

stopwatch watch;
int Stype;

void decide(int sensors) {	// line following
int temp=0;
if (ShiningPath.Indicator >= ShiningPath.Instruct.size() && ShiningPath.Instruct.size()!= 0) {
		temp=ShiningPath.Loc[ShiningPath.Indicator-1];
		cout << "location index " << temp << endl;
		ShiningPath = MarcoPolo(Stype, supervision, temp);
		ShiningPath.Indicator = 0;
	}
if ((ShiningPath.Instruct[ShiningPath.Indicator] == SPINBACK || ShiningPath.Instruct[ShiningPath.Indicator] == STOP || ShiningPath.Instruct[ShiningPath.Indicator] == LEFTSPINBACK || ShiningPath.Instruct[ShiningPath.Indicator] == RIGHTSPINBACK )){ 
	ShiningPath.Indicator++;
	cout << "i got " << ShiningPath.Indicator << " instructions" << endl;
	Crossroads(ShiningPath.Indicator-1);
}
const int Kp = 24;
const int Kd = 16;
const float Ki = 0.3;	// proportional, integral and derivative constants - need testing
static int prev = sensors; // holds the previous position of the line follower
//if (prev == 15) Kd = 3;
static float I = 0; // initialise integral control
static int olderror = 0; // initialise proportional control
int errorterm = 0;
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
}
int P = Kp*errorterm;
I = I + errorterm*Ki;
int D = (errorterm - olderror)*Kd;
int control = P+I+D;				// implements PID control		
bool direction = RIGHT;
if (control < 0) {
	control = -control;
	direction = LEFT;
}
//if (sensors == 0) control = 0;
if (control > MAXSPEED*THROTTLE) control = MAXSPEED*THROTTLE;
olderror = errorterm;	// avoids messing up derivative control at junctions
veer(direction, control);
if (sensors != 0) prev = sensors;		// updates last position unless it's lost
//cout << "elapsed " << watch.read() << endl;
}

void Crossroads(int junctcount) {
	int dist, threshold;
	int dir = ShiningPath.Instruct[junctcount];
	if (junctcount == MAXSPEED) dir = FORWARD;		// kludge for unintended uses
	
	int linereps = 0;
	int input = 8*1+4*1+2*1+1*1;
	bool line1 = false;
	switch (dir) {
		case STOP:
		stop();
		delay(100000);
		break;
		
		case PAUSE:
		switch (ShiningPath.Loc[junctcount]){
			case INGLIS:
			case BAKER:
			threshold = 82;
			break;
			
			case CEBON:
			threshold = 155;
			break;
		}
		dist = readDistance();
		while (dist < threshold) {
			Crossroads(MAXSPEED);				// kludge to make it go ahead
			Advance();
			dist = readDistance();
		}
		stop();
		Manipulate(!supervision);
		if (supervision == false) {
			Stype = Identify();
			cout << Stype << endl;
		}
		supervision = !supervision;
		break;
		
		case SPINBACK:
		stop();
		straightRun(REVERSE);
		delay(150/THROTTLE);
		swivel(LEFT, 0.8*MAXSPEED);
		delay(600);
		input = readLF();
		cout << "hi" << endl;
		while (linereps < 8 || line1 == false) {
			swivel(LEFT, 0.8*MAXSPEED);
			delay(35);
			input = readLF();
			if (input != 0 && input != 15) linereps++;
			else linereps = 0;
			if (linereps == 8 && line1 == false) {
					line1 = true;
					linereps = 0;
			}
		}
		break;
		
		case LEFTSPINBACK:
		case RIGHTSPINBACK:
		case LEFT:
		case RIGHT:
		if (dir != LEFTSPINBACK && dir != RIGHTSPINBACK) {
			straightRun(MAXSPEED*THROTTLE);
			delay(550/THROTTLE);
		}
		else {
			if (dir == LEFTSPINBACK) dir = LEFT;
			else dir = RIGHT;
		}
		swivel(dir, MAXSPEED*0.9);
		delay(500);
		input = readLF();
		while (linereps < 8) {
			swivel(dir, 0.9*MAXSPEED);
			delay(35);
			input = readLF();
			if (input != 0 && input != 15) linereps++;
			else linereps = 0;
		}
		break;
		
		
		case LEFTPAUSE:
		straightRun(MAXSPEED*THROTTLE);
		delay(450/THROTTLE);
		swivel(LEFT, MAXSPEED*0.8);
		delay(800);
		input = readLF();
		while (linereps < 8) {
			swivel(LEFT, 0.8*MAXSPEED);
			delay(35);
			input = readLF();
			if (input != 0 && input != 15) linereps++;
			else linereps = 0;
		}
		watch.start();
		while (watch.read() < 1250) {
			Advance();
		}
		stop();
		Manipulate(!supervision);
		if (supervision == false) {
			Stype = Identify();
			cout << Stype << endl;
		}
		watch.start();
		while (watch.read() < 150) {
			Advance();
		}
		supervision = !supervision;
		break;
		
		case RIGHTPAUSE:
		straightRun(MAXSPEED*THROTTLE);
		delay(450/THROTTLE);
		swivel(RIGHT, MAXSPEED*0.8);
		delay(800);
		input = readLF();
		while (linereps < 8) {
			swivel(RIGHT, 0.8*MAXSPEED);
			delay(35);
			input = readLF();
			if (input != 0 && input != 15) linereps++;
			else linereps = 0;
		}
		watch.start();
		while (watch.read() < 100) {	
			Advance();
		}
		stop();
		Manipulate(!supervision);
		if (supervision == false) {
			Stype = Identify();
			cout << Stype << endl;
		}
		supervision = !supervision;
		break;
				
		case FORWARD:
		default:
		straightRun(MAXSPEED*THROTTLE);
		while (input == 15) input = readLF();
		break;				
	}	
}
