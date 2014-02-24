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
#define RIGHT 0
#define MAXSPEED 127

extern robot_link rlink;

void straightRun(int speed);
void reverse(int speed);
void veer(bool right, int speed);
void sharpturn(bool right, int speed);
void stop();

