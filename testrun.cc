#include "header.h"
NavInstructions ShiningPath;

int main(){
initialise();
OpenClamp(5000);
int go=0;
cin>>go;
tests(go);
}

void tests (int go) {
switch (go) {
case 1: 				// straight line, no following
straightRun(MAXSPEED);
delay(7000);
break;

case 2:					// reverse
straightRun(REVERSE);
delay(7000);
break;

case 3:					// veer to the left slowly
swivel(LEFT,MAXSPEED);
delay(50000);
break;

case 4:					// calibrate the Identify function
cout << readLight() << endl;
OpenClamp(2500);
delay(1000);
CloseClamp();
cout << "light sensing " << readLight() << endl;
cout << "uswitch " << readuSwitch() << endl;
Identify();
break;

case 5:					// test microswitch
for (int i = 0; i<1000; i++) {
bool clamped = readuSwitch();
cout << clamped << endl;
delay(500);
}
break;

case 6:					// test LED outputs
for (int i = 0; i<1000; i++) {
lightLEDs(true, false, false, false);
delay(200);
lightLEDs(false, true, false, false);
delay(200);
lightLEDs(false, false, true, false);
delay(200);
lightLEDs(false, false, false, true);
delay(200);
lightLEDs(false, false, false, false);
}
break;

case 7:					// test light sensor
for (int i = 0; i<1000; i++) {
int light = readLight();
cout << light << endl;
delay(500);
}
break;

case 8:					// test distance sensor
for (int i = 0; i<1000; i++) {
int distance = readDistance();
cout << distance << endl;
delay(500);
}
break;

case 9:					// test actuator
for (int i = 0; i<5; i++) {
RaiseLever();
LowerLever();
}
break;

case 10:				// test clamp
delay(2000);
CloseClamp();
cout<<"Testy"<<endl;
break; 

case 11: 				// line following
cout<<"WTF1"<<endl;
ShiningPath = MarcoPolo(Lingerie, false, START);
cout<<"WTF2"<<endl;
for (unsigned int i=0; i<ShiningPath.Instruct.size(); i++){
	cout << ShiningPath.Instruct[i] << " lol" << endl;
}
cout<<"WTF3!!"<<endl;
while (true) {
int input=readLF();
decide(input);
}
break;

}
}


