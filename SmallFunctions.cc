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
rlink.command(MOTOR_1_GO, 128+(0.9*MAXSPEED));
rlink.command(MOTOR_2_GO, (0.9*MAXSPEED)-speed);
 }
else {
rlink.command(MOTOR_1_GO, 128+(0.9*MAXSPEED)-speed);
rlink.command(MOTOR_2_GO, 0.9*MAXSPEED);
 }	
}

void swivel(bool right, int speed){
if (right) rlink.command(BOTH_MOTORS_GO_SAME, 128+speed);
else rlink.command(BOTH_MOTORS_GO_SAME, speed);
}

int readLF() {
return rlink.request(READ_PORT_5)%16;
}

void stop(){
rlink.command(BOTH_MOTORS_GO_SAME, 0);
}

int Identify(){
	enum Stype {Lingerie, Green, Yellow, Invshroom, Burkha};
	int Stype=Burkha;
	int lightlv = readLight();
	if (lightlv >= 80) Stype = Yellow;
	if (lightlv >= 140) Stype = Green;
	if (lightlv >= 160) Stype = Invshroom;
	if (lightlv >= 190) Stype = Lingerie;
	return Stype;
}

void Manipulate(bool pickup){
   if (pickup){
     LowerLever();//Not sure necessary?
     CloseClamp(); 
     RaiseLever();
   }
   else{
   OpenClamp(4000);
   }
}

void RaiseLever(){
rlink.command (WRITE_PORT_5, 32*1);
delay(500);
cout<<"Lever Up"<<endl;
}
void LowerLever(){
rlink.command (WRITE_PORT_5, 32*0);
cout<<"Lever Down"<<endl; 
//delay(1150);
}
void OpenClamp(int timelength){
	cout<<"Opening Clamp"<<endl;
   rlink.command(MOTOR_3_GO, MAXSPEED);
   delay(timelength);
   rlink.command(MOTOR_3_GO, 0);
}
void CloseClamp(){
	cout<<"Closing Clamp"<<endl;
   rlink.command(MOTOR_3_GO, 128+MAXSPEED);
   while(readuSwitch() == true) delay(20);
   cout<<"Switched"<<endl;
   delay(1200);
   rlink.command(MOTOR_3_GO, 0);
}

void Advance(){
int input=readLF();
decide(input);
//int distance = rlink.request (ADC0);
//cout << distance << endl;
//Advance();
}

int readDistance(){
return rlink.request(ADC0);
}

int readLight(){
return rlink.request(ADC2);
}

void lightLEDs(bool led1, bool led2,bool led3, bool led4) {
rlink.command (WRITE_PORT_2, 2*led1+4*led2+16*led3+32*led4);
}

bool readuSwitch() {
int out = rlink.request(READ_PORT_5);
if (out%32 > 16) return 1;
else return 0;
}



