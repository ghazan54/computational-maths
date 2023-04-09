#!/bin/bash

g++ -g -Wall -Wextra Euler/euler.cpp Runge-Kutta/rc.cpp main.cpp -o ode.out -I. -fopenmp
