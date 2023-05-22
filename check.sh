#!/bin/bash


printf "\nRunning bash grade\n" && sleep 1
bash grade
printf "\nRunning Tidy\n" && sleep 1
make tidy
printf "\nRunning valgrind\n" && sleep 1
make valgrind
printf "\nRunning clean\n" && sleep 1
make clean
