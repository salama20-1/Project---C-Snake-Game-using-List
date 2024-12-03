#include "Food.h"
#include "MacUILib.h"
#include "string.h"
#include <stdlib.h>
#include <time.h>

// Constructor to initialize food position and symbol
Food::Food() 
{
    foodPos.pos->x = 0;
    foodPos.pos->y = 0;
    foodPos.symbol = '\0';
}

// Destructor - no dynamic memory to release in this case
Food::~Food() 
{
    // No heap memory allocated, so nothing to delete
}

// Generates a random position for the food and ensures it doesn't overlap with the player
void Food::generateFood(objPosArrayList* blockOff)
{
    // Randomization seed
    srand(time(NULL));

    // Fixed symbol for food
    const char fixedSymbol = 'X';

    bool foodGenerated = false;

    // Loop until a valid food position is found
    while (!foodGenerated) {
        // Randomly generate a position within the board bounds
        int randomX = rand() % 29 + 1;
        int randomY = rand() % 14 + 1;

        // Set food position
        foodPos.pos->x = randomX;
        foodPos.pos->y = randomY;

        // Check if the food overlaps with any player's position
        bool overlaps = false;
        int playerSize = blockOff->getSize();
        for (int i = 0; i < playerSize; ++i) {
            objPos playerSegment = blockOff->getElement(i);
            if (playerSegment.pos->x == foodPos.pos->x && playerSegment.pos->y == foodPos.pos->y) {
                overlaps = true;
                break;
            }
        }

        // If no overlap, food generation is successful
        if (!overlaps) {
            foodPos.symbol = fixedSymbol;
            foodGenerated = true;
        }
    }
}

// Returns the position of the food
objPos Food::getFoodPos() const
{
    return foodPos;
}

