#include "header.h"

bool junct;
int junct_count;

void decide(int sensors) {
//obviously Values need testing
static int prev = sensors; // holds the previous position of the line follower
switch (sensors) {
//Need to check which sensors are meant to be on the line, and whetherline is on or off.
case 8*0+4*1+2*1+1*0: // central sensors detect a line
straightRun(MAXSPEED);
prev = sensors;
break;

case 8*0+4*0+2*0+1*0: // no line detected
stop();
cout << "Lost the line" << endl;
//decide(prev);
break;

case 8*0+4*0+2*0+1*1: // rightmost sensor only
veer(RIGHT, MAXSPEED);
prev = sensors;
break;

case (8*0+4*0+2*1+1*0):
case (8*0+4*1+2*0+1*0):
case (8*0+4*1+2*0+1*1):
case (8*1+4*0+2*0+1*1): 
case (8*1+4*0+2*1+1*1):
case (8*1+4*1+2*0+1*1):
cout << "wtf?" << endl;
decide(prev);
break;
//Some of these depend on how far apart the sesnors are on whether they are WTF or not. Needs Examining.

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
cout << "Junction detected!" << endl;
junct = true;
junct_count++;
// insert pathfinding code here
prev = sensors;
break;
}
}
