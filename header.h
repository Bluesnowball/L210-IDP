#include <iostream>
#include <fstream>
#include <robot_instr.h>
#include <robot_link.h>
#include <delay.h>
#include <math.h>
#include <stopwatch.h>
using namespace std;

#define ROBOT_NUM 10
#define LEFT 0
#define RIGHT 1
#define MAXSPEED 127

void initialise();
void straightRun(int speed);
void reverse(int speed);
void veer(bool right, int speed);
void swivel(bool right, int speed);
void stop();
void tests(int go);
void decide (int sensors);
