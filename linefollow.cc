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


}

void decide(int sensors) {
	static int prev = sensors; // holds the previous position of the line follower
	switch (sensors) {
		case 8*0+4*1+2*1+1*0:
		straightRun(MAXSPEED);
		prev = sensors;
		break;
		
		case 8*0+4*0+2*0+1*0:
		stop();
		cout << "Lost the line" << endl;
		decide(prev);
		break;
		
		case 8*0+4*0+2*0+1*1:
		veer(LEFT, MAXSPEED);
		prev = sensors;
		break;
		
		case (8*0+4*0+2*1+1*0 || 8*0+4*1+2*0+1*0 || 8*0+4*1+2*0+1*1 || 8*1+4*0+2*0+1*1 || 8*1+4*1+2*1+1*0 || 8*1+4*0+2*1+1*1 || 8*1+4*1+2*0+1*1):
		cout << "wtf?" << endl;
		decide(prev);
		break;
		
		case 8*0+4*0+2*1+1*1:
		veer(LEFT, 50);
		prev = sensors;
		break;
		
		case 8*0+4*1+2*1+1*1:
		veer(RIGHT, 50);
		prev = sensors;
		break;
		
		case 8*0+4*1+2*1+1*1:
		swivel(RIGHT, 50);
		prev = sensors;
		break;
		
		case 8*1+4*0+2*0+1*0:
		veer(RIGHT, MAXSPEED);
		prev = sensors;
		break;
		
		case 8*1+4*1+2*0+1*0:
		veer(RIGHT, 50);
		prev = sensors;
		break;
		
		case 8*1+4*1+2*1+1*0:
		swivel(RIGHT, 50);
		prev = sensors;
		break;
		
		case 8*1+4*1+2*1+1*1:
		cout << "Junction detected!"
		junct = true;
		junct_count++;
		// insert pathfinding code here
		prev = sensors;
		break;
	}
}
