#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define len 100

extern double stack[len + 1];
extern double pop_value;
bool push(double value);
bool pop();