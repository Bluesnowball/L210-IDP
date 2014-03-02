#include "header.h"

robot_link rlink;

void initialise() {
#ifdef __arm__
   if (!rlink.initialise ("127.1.1.1")) { // setup for local hardware
#else
   if (!rlink.initialise (ROBOT_NUM)) { // setup the link
#endif
  cout << "Cannot initialise link" << endl;
  rlink.print_errs(" ");
  return; // error, finish
}
}

void straightRun(int speed){
rlink.command (RAMP_TIME, 255);
rlink.command(BOTH_MOTORS_GO_OPPOSITE, 128+speed);
}

void veer(bool right, int speed){
if (right) {
rlink.command(MOTOR_1_GO, 128+MAXSPEED);
rlink.command(MOTOR_2_GO, MAXSPEED-speed);
 }
else {
rlink.command(MOTOR_1_GO, 255-speed);
rlink.command(MOTOR_2_GO, MAXSPEED);
 }
}

void swivel(bool right, int speed){
if (right) rlink.command(BOTH_MOTORS_GO_SAME, 128+speed);
else rlink.command(BOTH_MOTORS_GO_SAME, speed);
}

int readLF() {
return rlink.request(READ_PORT_5);
}

void stop(){
rlink.command(BOTH_MOTORS_GO_SAME, 0);
}
