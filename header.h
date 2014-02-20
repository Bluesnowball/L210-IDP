#include <iostream>
#include <fstream>
#include <robot_instr.h>
#include <robot_link.h>
#include <delay.h>
#include <math.h>
#include <stopwatch.h>
using namespace std;

#define ROBOT_NUM 10

extern robot_link rlink;

void straightRun(int speed);
void reverse(int speed);
void veer(bool left, int speed);
void sharpturn(bool left, int speed);
void stop();

