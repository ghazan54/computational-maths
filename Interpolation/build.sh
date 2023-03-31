#!/bin/bash

g++ -Wall -Wextra Lagrange/lagrange.cpp Aitken/aitken.cpp Newton/newton.cpp main.cpp -o interpolation.out -I.