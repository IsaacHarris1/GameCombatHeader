#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <vector>
#include <limits>
#include <random>
#include <ctime>
#include <fstream>

void clearScreen();
int basicD20Roll();
int inputValidation();
char inputCharValidation();
int rollHelper(int amountRoll, std::mt19937& rng, std::uniform_int_distribution<int>& dist);
int diceRoll();

#endif