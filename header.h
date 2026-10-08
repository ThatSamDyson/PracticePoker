#pragma once
#include <string>

#ifndef HEADER_H
#define HEADER_H

int firstDraw();
int secondDraw();
void playerChoice();
void invalidInput();

int firstCard = 0;
int secondCard = 0;
int thirdCard = 0;
int fourthCard = 0;
int fifthCard = 0;


int handWorth = 0;

std::string cValue[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "King", "Queen", "Jack"};
std::string cFace[4] = {"Diamonds", "Clubs", "Spades", "Hearts"};
#endif