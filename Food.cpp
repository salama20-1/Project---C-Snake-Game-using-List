#include "MacUILib.h"
#include "string.h"
#include <stdlib.h>
#include <time.h>
#include "Food.h"

// default constructor to initialize food position and symbol
Food::Food()
{
    foodPos.symbol = '\0'; // No symbol initially assigned
    foodPos.pos->x = 0;
    foodPos.pos->y = 0;
}

// destructor does nothing as no dynamic memory allocation is used
Food::~Food()
{
    // no cleanup required as no heap memory is allocated
}

// generates a valid food position on the board, avoiding the player
void Food::generateFood(objPosArrayList* blockOff)
{
    const char foodSymbol = 'X';  // food symbol to be placed
    bool foodPlaced = false;      // flag to check if the food is successfully placed

    srand(time(NULL));  // initialize the random seed

    while (!foodPlaced) {
        // generate random coordinates within the grid
        int randX = rand() % 29 + 1;
        int randY = rand() % 14 + 1;

        foodPos.pos->x = randX;
        foodPos.pos->y = randY;

        // check for overlap with any player block
        if (!isOverlapWithPlayer(blockOff)) {
            foodPos.symbol = foodSymbol;  // assign food symbol if no overlap
            foodPlaced = true;  // successfully placed food
        }
    }
}

// checks if the generated food position overlaps with any player's position
bool Food::isOverlapWithPlayer(objPosArrayList* blockOff)
{
    int blockCount = blockOff->getSize();

    for (int i = 0; i < blockCount; ++i) {
        objPos currentBlock = blockOff->getElement(i);
        if (currentBlock.pos->x == foodPos.pos->x && currentBlock.pos->y == foodPos.pos->y) {
            return true;  // overlap detected
        }
    }

    return false;  // no overlap
}

// returns the position of the food
objPos Food::getFoodPos() const
{
    return foodPos;
}


