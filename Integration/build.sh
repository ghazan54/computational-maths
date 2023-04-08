#!/bin/bash

g++ -g -Wall -Wextra trapezoidal/trapezoidal.cpp midpoint/midpoint.cpp 'monte carlo/mc.cpp' main.cpp -o integration.out -I. -fopenmp