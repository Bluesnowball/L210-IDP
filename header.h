#include <iostream>
#include <fstream>
#include <vector>
#include <robot_instr.h>
#include <robot_link.h>
#include <delay.h>
#include <math.h>
#include <stopwatch.h>
using namespace std;

#define ROBOT_NUM 10
enum {LEFT, RIGHT, FORWARD, SPINBACK, PAUSE, STOP,LEFTPAUSE,RIGHTPAUSE};//instruction enums
enum {START, INGLIS, BAKER, CEBON, SUTCLIFFE, VENKATARAMANAN,WORKSHOP,MATLAB,CAPE,DPO,EIETL,K2,ENDOFTERM,}; // location enums
enum {Lingerie, Green, Yellow, Invshroom, Burkha};
#define MAXSPEED 127
#define REVERSE 255
#define THROTTLE 0.82


class NavInstructions{
 public:
  string name;
  unsigned int Indicator;
  vector<int> Instruct;
  vector<int> Loc; };
void initialise();
void straightRun(int speed);
void veer(bool right, int speed);
void fastVeer(bool right, int speed);
void swivel(bool right, int speed);
void stop();
void tests(int go);
void decide (int sensors); 		// line following
void Crossroads(int junct_count);
int readLF();
NavInstructions MarcoPolo(int Stype,bool justpick,int loc);
int Identify();
void Manipulate(bool pickup);
void RaiseLever();
void LowerLever();
void OpenClamp(int timelength);
void CloseClamp();
int Lost(int prev);
void ProfligateNavigate(NavInstructions Instr);
void Advance();
int readDistance();
int readLight();
void lightLEDs(bool led1,bool led2, bool led3, bool led4);
bool readuSwitch();

extern NavInstructions ShiningPath;
