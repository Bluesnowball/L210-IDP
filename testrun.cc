#include "header.h"

robot_link rlink;

int main(){
initialise();
int go=0;
cin>>go;
tests(go);
}

void tests (int go) {
switch (go) {
case 1:
straightRun(MAXSPEED);
delay(7000);
break;

case 2:
reverse(MAXSPEED);
delay(7000);
break;

case 3:
veer(LEFT,50);
delay(500);
break;

case 4:
veer(LEFT, MAXSPEED);
delay(2500);
break;

case 5:
veer(RIGHT,MAXSPEED);
delay(2500);
break;

case 6:
swivel(LEFT,MAXSPEED);
delay(1500);
break;

case 7:
swivel(RIGHT,MAXSPEED);
delay(3000);
break;

case 8:
swivel(RIGHT,50);
delay(3000);
break;

case 9:
veer(RIGHT,MAXSPEED*0.9);
delay(3000);
break;

case 10:
//rlink.command(MOTOR_4_GO, MAXSPEED);
rlink.command(MOTOR_3_GO, MAXSPEED);
delay(5000);
break;

case 11: // line following
int input=rlink.request (READ_PORT_3);
cout << input << endl;
decide(input);
delay(100);
tests(11);
break;
}
}

void initialise() {
	#ifdef __arm__
   if (!rlink.initialise ("127.0.0.1")) { // setup for local hardware
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

void reverse(int speed){
rlink.command (RAMP_TIME, 255);
rlink.command(BOTH_MOTORS_GO_OPPOSITE, speed);
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

void stop(){
rlink.command(BOTH_MOTORS_GO_SAME, 0);
}



