#pragma once
#define MATRIXTOOLS

// Here are the matrix's main functions
// to draw in the screen

#include <iostream>
#include <unistd.h>
#include <cmath>
#include "simulator_settings.h"


// Function to clear the matrix array
void clearMatrix();

// Function to draw frame from matrix's to the screen
void drawFrame();

// Function to add a dot to the matrix, so that it can be drawn later
void addDot(int, int, char);

