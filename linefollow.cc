#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#include <robot_delay.h>
#include <stopwatch.h>
#include <header.h>
#define ROBOT_NUM 10 // The id number (see below)
#define LEFT 1
#define RIGHT 0
#define MAXSPEED 126
robot_link rlink; // datatype for the robot link

bool junct;
int junct_count;


int main ()
{ // data from microprocessor
	#ifdef __arm__
   if (!rlink.initialise ("127.0.0.1")) {          // setup for local hardware
#else
   if (!rlink.initialise (ROBOT_NUM)) { // setup the link
#endif
  cout << "Cannot initialise link" << endl;
  rlink.print_errs(" ");
  return -1; // error, finish
}
// get some input from the sensors
// call decide() with the sensor input

}

void decide(int sensors) {
	static int prev = sensors; // holds the previous position of the line follower
	switch (sensors) {
		case 8*0+4*1+2*1+1*0:  // central sensors detect a line
		straightRun(MAXSPEED);
		prev = sensors;
		break;
		
		case 8*0+4*0+2*0+1*0: // no line detected
		stop();
		cout << "Lost the line" << endl;
		decide(prev);
		break;
		
		case 8*0+4*0+2*0+1*1: // rightmost sensor only
		veer(RIGHT, MAXSPEED);
		prev = sensors;
		break;
		
		case (8*0+4*0+2*1+1*0 || 8*0+4*1+2*0+1*0 || 8*0+4*1+2*0+1*1 || 8*1+4*0+2*0+1*1 || 8*1+4*1+2*1+1*0 || 8*1+4*0+2*1+1*1 || 8*1+4*1+2*0+1*1):
		cout << "wtf?" << endl;
		decide(prev);
		break;
		
		case 8*0+4*0+2*1+1*1: // 2 sensors on the right - probably veering off the line
		veer(RIGHT, 50);
		prev = sensors;
		break;
		
		case 8*0+4*1+2*1+1*1: // 3 sensors on the right - probably at an angle
		swivel(RIGHT, 50);
		prev = sensors;
		break;
		
		case 8*1+4*0+2*0+1*0: // leftmost sensor only
		veer(LEFT, MAXSPEED);
		prev = sensors;
		break;
		
		case 8*1+4*1+2*0+1*0: // 2 sensors on left
		veer(LEFT, 50);
		prev = sensors;
		break;
		
		case 8*1+4*1+2*1+1*0: // 3 sensors on left - probs at an angle
		swivel(LEFT, 50);
		prev = sensors;
		break;
		
		case 8*1+4*1+2*1+1*1: // at a junction
		cout << "Junction detected!"
		junct = true;
		junct_count++;
		// insert pathfinding code here
		prev = sensors;
		break;
	}
}
