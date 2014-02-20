#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#define ROBOT_NUM 10   // The id number (see below)
robot_link rlink;      // datatype for the robot link
void straightRun(int speed), reverse(int speed), veer(bool left, int speed), sharpturn(bool left, int speed), stop;

int main ()
{                          // data from microprocessor
if (!rlink.initialise (ROBOT_NUM)) { // setup the link
  cout << "Cannot initialise link" << endl;
  rlink.print_errs("  ");
  return -1;               // error, finish
}

straightRun(127);
delay(3000);
float stat = rlink.request (STATUS);
cout<<stat;
veer(true, 50);
delay(5000);
sharpturn(false, 127);
delay(2500);
stop;
}

void straightRun(int speed){
rlink.command (RAMP_TIME, 255);
rlink.command(BOTH_MOTORS_GO_SAME, speed);
}

void reverse(int speed){
rlink.command (RAMP_TIME, 255);
rlink.command(BOTH_MOTORS_GO_SAME, 128+speed);  
}

void veer(bool left, int speed){
if (left) rlink.command(MOTOR_2_GO, 127-speed);
else rlink.command(MOTOR_2_GO, 127-speed);
}

void sharpturn(bool left, int speed){
if (left) rlink.command(BOTH_MOTORS_GO_OPPOSITE, speed);
else rlink.command(BOTH_MOTORS_GO_OPPOSITE, 128+speed);
}

void stopMoving{
rlink.command(BOTH_MOTORS_GO_SAME, 0);
}
