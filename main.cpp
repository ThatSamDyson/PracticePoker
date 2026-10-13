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
        std::cout << "\033[H\033[2J" << std::flush; 
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

     if (cardsDrawn < 2)
     {
        std::this_thread::sleep_for(std::chrono::seconds(1)); 

        draw();

     }


    int sum = std::accumulate(card.begin(), card.end(), 0);
    std::cout << "Your hand: " << sum << "\n";

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
        std::this_thread::sleep_for(std::chrono::seconds(1)); 

        computerDraw();
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

void computerDraw()
{
    std::srand(time(NULL));

    int drawnCard = rand() % 13; //Draws Card
    int x = computerCardsDrawn;
    computerCard[x] = drawnCard;

    std::cout << "Your opponent drew " << cValue [drawnCard] << " of " << cFace[rand() % 4] << std::endl;

    if (computerCard[x] > 10)
    {
        computerCard[x] = 10;
    }

    else if  (computerCard[x] == 1)
    {
        computerCard [x] = 10;
    }

    else if (computerCard[x] == 0)
    {
        computerCard[x] = 11;
    }

     computerCardsDrawn = computerCardsDrawn +1;

     if (computerCardsDrawn < 2)
     {
        std::this_thread::sleep_for(std::chrono::seconds(1)); 
        computerDraw();
     }

     int computerSum = std::accumulate(computerCard.begin(), computerCard.end(), 0);
    std::cout << "Their hand: " << computerSum << "\n";

    if (computerSum == 21)
    {
        std::cout << "Your opponent wins!" << std::endl;
        endGame();
    }

    if (computerSum > 21)
    {
        std::cout << "Your opponent busted out!" << std::endl;
        endGame();
    }

    if (computerCardsDrawn == 5)
    {
        std::cout << "Your opponent got a five card Charlie" << std::endl;
        std::cout << "Your opponent wins!" << std::endl;
        endGame();
    }

    playerChoice();
}

void computerLogic()
{
    if (computerSticks == true)
    {
        checkStuck();
    }

    int computerRandNum = rand() % 99;

    if (computerSum == 20)
    {
        if (computerRandNum == 99)
        {
            computerDraw();
        }

        else 
        {
            computerSticks = true;
        }
    }
}

void checkStuck()
{
 if ((playerSticks = true) && (computerSticks = true))
 {
    if (sum > computerSum)
    {
        std::cout << "The player wins!" << std::endl;
        
        endGame();
    }

    else if (sum < computerSum)
    {
        std::cout << "The computer wins!" << std::endl;
        
        endGame();
    }

    else if (sum == computerSum)
    {
        std::cout << "The hand is tied" << std::endl;
        
        endGame();
    }
 }

 else if (playerSticks == true)
 {
    computerLogic();
 }

 else if (computerSticks == true)
 {
    playerChoice();
 }
}

int main()
{
draw();

return 0;

}