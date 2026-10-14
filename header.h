#pragma once
#include <string>
#include <array>
#include <algorithm>
#include <numeric>

#ifndef HEADER_H
#define HEADER_H

void checkStuck();
void invalidInput();
void check21();
void endGame();
void draw();
void computerLogic();
void restartGame();
void computerChoice();
void computerDraw();
void playerChoice();


int cardsDrawn = 0;
int computerCardsDrawn = 0;
int sum;
int computerSum;
int computerRandNum;
bool playerSticks;
bool computerSticks;
bool playerFirstDraw = true;
bool computerFirstDraw = true;
bool gameOver = false;
bool wonHand = false;
bool lostHand = false;

std::array<int, 5> card = {0, 0, 0, 0, 0};
std::array<int, 5> computerCard = {0, 0, 0, 0, 0};

int playerMoney = 1000;
int computerMoney = 1000;


std::string cValue[13] = {"Ace", "Jack", "2", "3", "4", "5", "6", "7", "8", "9", "10", "King", "Queen"};
std::string cFace[4] = {"Diamonds", "Clubs", "Spades", "Hearts"};
#endif