#pragma once
#include <string>
#include <array>
#include <algorithm>
#include <numeric>

#ifndef HEADER_H
#define HEADER_H



int firstDraw();
int secondDraw();
void thirdDraw();
int fourthDraw();
int fifthDraw();
void playerChoice();
void invalidInput();
void check21();
void endGame();
void draw();
void restartGame();

int cardsDrawn = 0;
bool gameOver = false;
bool wonHand = false;
bool lostHand = false;

std::array<int, 5> card = {0, 0, 0, 0, 0};


int handWorth = 0;

std::string cValue[13] = {"Ace", "Jack", "2", "3", "4", "5", "6", "7", "8", "9", "10", "King", "Queen"};
std::string cFace[4] = {"Diamonds", "Clubs", "Spades", "Hearts"};
#endif