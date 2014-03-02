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
straightRun(REVERSE);
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
delay(3111);
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


