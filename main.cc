#include "header.h"
NavInstructions ShiningPath;
stopwatch runtimer;

int main(){
initialise();
runtimer.start();
lightLEDs(false, false, false, false);
CloseClamp();
OpenClamp(8000);
ShiningPath = MarcoPolo(Lingerie, false, START);
for (unsigned int i=0; i<ShiningPath.Instruct.size(); i++){
	cout << ShiningPath.Instruct[i] << endl;
}
while (runtimer.read() < 240000) {
int input=readLF();
decide(input);
}
while (runtimer.read() < 300000) {
int input=readLF();
decide(input);
if(ShiningPath.Loc[ShiningPath.Indicator] == INGLIS) {
	ShiningPath = MarcoPolo(0,0,INGLIS);
}
}
}
