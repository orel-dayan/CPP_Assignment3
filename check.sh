#!/bin/bash
#Run script from a linux device, and make sure the script is located in the relevant location where the makefile is.

printf "\nRunning bash grade\n" && sleep 1
bash grade
printf "\nRunning Teddie\n" && sleep 1
make tidy
printf "\nRunning valgrind\n" && sleep 1
make valgrind
printf "\nRunning clean\n" && sleep 1
make clean