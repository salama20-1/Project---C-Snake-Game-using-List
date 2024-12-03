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
        // Direction state
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  

        Food();
        ~Food();

        void generateFood(objPosArrayList* blockOff);
        objPos getFoodPos() const; // Upgrade this in iteration 3. 
        
        // does food position overlap with player position?
        bool isOverlapWithPlayer(objPosArrayList* blockOff);  // add this function prototype

    private:
        objPos foodPos; // Upgrade this in iteration 3.

};

#endif
