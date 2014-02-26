#include <iostream>
#include <fstream>
#include <robot_instr.h>
#include <robot_link.h>
#include <delay.h>
#include <math.h>
#include <stopwatch.h>
using namespace std;

#define ROBOT_NUM 10  // connects to the right robot
#define LEFT 0
#define RIGHT 1
#define FORWARD 2
#define BACK 3
#define MAXSPEED 127
#define REVERSE 255

void initialise();
void straightRun(int speed);
void veer(bool right, int speed);
void swivel(bool right, int speed);
void stop();
void tests(int go);
void decide (int sensors);  // line following
