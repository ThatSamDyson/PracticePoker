#include <iostream>
#include "header.h"
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>

int firstDraw()
{
    std::srand(time(NULL));
        firstCard = rand() % 14;
    std::cout << "You drew " << cValue[firstCard] << " of " << cFace[rand() % 4] << std::endl;

    //firstCard = rand() % 14;
    std::cout << firstCard << std::endl;

    if (firstCard > 10)
    {
        firstCard = 10; 
    }

    else if (firstCard == 0)
    {
        firstCard = 11
        
    }

    return 0;

}

int secondDraw()
{

    std::srand(time(NULL));
    secondCard = rand() % 14;
    std::cout << "You drew " << cValue[secondCard] << " of " << cFace[rand() % 4] << std::endl;

    

    if (secondCard > 10)
    {
        secondCard = 10; 
    }

    std::cout << secondCard << std::endl;

    return 0;

}

int handValue()
{
    handWorth = firstCard + secondCard + thirdCard + fourthCard + fifthCard;

    std::cout << "Your current hand is worth " << handWorth << std::endl;

    return 0;
}

void playerChoice()
{
int playerInput;

    std::cout << "What would you like to do?" << std::endl;
    std::cout << "1. Draw | 2. Stick | 3. Fold" << std::endl;
    std::cin >> playerInput;

    if (playerInput == 1)
    {
        std::cout << "You draw another card" << std::endl;
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

int main()
{
   firstDraw();

   std::this_thread::sleep_for(std::chrono::seconds(1)); //Delay between draws

   secondDraw();

   handValue();

   playerChoice();

}