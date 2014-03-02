#include <iostream>
#include <fstream>
#include <vector>
#include <robot_instr.h>
#include <robot_link.h>
#include <delay.h>
#include <math.h>
#include <stopwatch.h>
#include <vector>
using namespace std;

#define ROBOT_NUM 11
#define LEFT 0
#define RIGHT 1
#define FORWARD 2
#define MAXSPEED 127
#define REVERSE 255

class NavInstructions{
 public:
  string name:
  int Indicator:
  vector<int> Instruct:
  vector<int> Loc: };
void initialise();
void straightRun(int speed);
void veer(bool right, int speed);
void swivel(bool right, int speed);
void stop();
void tests(int go);
void decide (int sensors);
void Crossroads(int junct_count);
int readLF();
NavInstructions MarcoPolo(Stype int);
int Identify();
void Manipulate();
void RaiseLever()
void LowerLever()
void OpenClamp()
void CloseClamp()
