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
rlink.command(MOTOR_1_GO, 128+(THROTTLE*MAXSPEED));
rlink.command(MOTOR_2_GO, (THROTTLE*MAXSPEED)-speed);
 }
else {
rlink.command(MOTOR_1_GO, 128+(THROTTLE*MAXSPEED)-speed);
rlink.command(MOTOR_2_GO, THROTTLE*MAXSPEED);
 }
}

void fastVeer(bool right, int speed) {
if (right) {
rlink.command(MOTOR_1_GO, 128+(0.58*MAXSPEED));
rlink.command(MOTOR_2_GO, (0.58*MAXSPEED)-speed);
 }
else {
rlink.command(MOTOR_1_GO, 128+(0.58*MAXSPEED)-speed);
rlink.command(MOTOR_2_GO, 0.58*MAXSPEED);
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

int Identify(){
   int Stype=4;
   return Stype;
   //If with microswitch, if yes then case with light value test, if not Stype=0
}
void Manipulate(bool pickup){
   if (pickup){
      LowerLever();//Not sure necessary?
     CloseClamp(); 
   }
   else{
   RaiseLever();
   OpenClamp();
   }
}

void RaiseLever(){
 //Guess what goes in here  
}
void LowerLever(){
   
}
void OpenClamp(){
   
}
void CloseClamp(){
   
}

void Advance(){}


