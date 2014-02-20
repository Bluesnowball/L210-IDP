#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#include <robot_delay.h>
#include <stopwatch.h>
#define ROBOT_NUM 10 // The id number (see below)
robot_link rlink; // datatype for the robot link


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
