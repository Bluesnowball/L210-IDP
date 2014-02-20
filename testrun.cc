#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#define ROBOT_NUM 10   // The id number (see below)
robot_link rlink;      // datatype for the robot link
void straightRun(int speed);
void reverse(int speed);
void veer(bool left, int speed);
void sharpturn(bool left, int speed);

int main ()
{                          // data from microprocessor
if (!rlink.initialise (ROBOT_NUM)) { // setup the link
  cout << "Cannot initialise link" << endl;
  rlink.print_errs("  ");
  return -1;               // error, finish
}

rlink.command (STOP_IF_HIGH, 0x05);
rlink.command (STOP_SELECT, 3);
rlink.command (RAMP_TIME, 255);
rlink.command(BOTH_MOTORS_GO_SAME, 127);
delay(2000);
delay(2000);
float stat = rlink.request (STATUS);
cout<<stat;
rlink.command(BOTH_MOTORS_GO_OPPOSITE, 127);
delay(2000);
delay(2000);
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
