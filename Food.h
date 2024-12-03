#ifndef FOOD_H
#define FOOD_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Food
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Food();
        ~Food();

        void generateFood(objPosArrayList* blockOff);
        objPos getFoodPos() const; // Upgrade this in iteration 3. 
        
        // Check if food position overlaps with any player's position
        bool isOverlapWithPlayer(objPosArrayList* blockOff);  // Add this function prototype

    private:
        objPos foodPos; // Upgrade this in iteration 3.

        // Need a reference to the Main Game Mechanisms
};

#endif
