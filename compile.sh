#!/bin/bash

# Compile File
# Feb 13 2020
# Michael Boyd
# mnb170030@utdallas.edu
# CS 3377.501 Spring 2020
# Verison 1.0
# Copyright 2020 All Rights Reserved

echo "Comiling Source Code."
g++ -c casingText.cc -c CaseSwitch.cc CaseSwitch.h -I ~/include/
echo "Linking Object Code."
g++ casingText.o CaseSwitch.o -o program2
echo "Done, program2 was created."
