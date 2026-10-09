#include <iostream>
#include "header.h"
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>

void playerChoice()
{
int playerInput;

    std::cout << "What would you like to do?" << std::endl;
    std::cout << "1. Draw | 2. Stick | 3. Fold" << std::endl;
    std::cin >> playerInput;

    if (playerInput == 1)
    {
        std::cout << "You draw another card" << std::endl;
        draw();
    }

    else if (playerInput == 2)
    {
    std::cout << "You stick with your cards" << std::endl;
    }
    
    else if (playerInput == 3)
    {
        std::cout << "You fold" << std::endl;
    }

    else
    {
        std::cout << playerInput << std::endl;
    }

}

void invalidInput()
{
 std::cout << "ERROR: Invalid Input! Please try again" << std::endl;

playerChoice();
}


void endGame()
{
    int endGameInput;

    std::cout << "Would you like to play again?" << std::endl;

    std::cout << "1. Yes | 2. No" << std::endl;

    std::cin >> endGameInput;

    if (endGameInput == 1)
    {
       restartGame();
    }
}

void draw()
{
    std::cout << "\033[H\033[2J" << std::flush; 

    std::srand(time(NULL));

    int drawnCard = rand() % 13; //Draws Card
    int i = cardsDrawn;
    card[i] = drawnCard; //Sets card value in Array

    
    std::cout << "You drew " << cValue [drawnCard] << " of " << cFace[rand() % 4] << std::endl;

    if (card[i] > 10)
    {
        card[i] = 10;
    }

    else if  (card[i] == 1)
    {
        card [i] = 10;
    }

    else if (card[i] == 0)
    {
        card[i] = 11;
    }

     cardsDrawn = cardsDrawn +1;


    int sum = std::accumulate(card.begin(), card.end(), 0);
    std::cout << "Total hand: " << sum << "\n";

    std::cout << "Cards Drawn: " << cardsDrawn << std::endl;

    if (sum == 21)
    {
        endGame();
    }

    if (sum > 21)
    {
        endGame();
    }

    if (cardsDrawn == 5)
    {
        endGame();
    }

    else
    {
        playerChoice();
    }


}

void restartGame()
{
    cardsDrawn = 0;
    card[0] = 0;
    card[1] = 0;
    card[2] = 0;
    card[3] = 0;
    card[4] = 0;

    std::cout << "\033[H\033[2J" << std::flush; 

    draw();
}

int main()
{
draw();

}