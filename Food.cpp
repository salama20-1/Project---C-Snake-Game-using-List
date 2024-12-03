#include "Food.h"
#include "MacUILib.h"
#include "string.h"
#include <stdlib.h>
#include <time.h>

// Default constructor to initialize food position and symbol
Food::Food()
{
    foodPos.pos->x = 0;
    foodPos.pos->y = 0;
    foodPos.symbol = '\0';  // No symbol initially assigned
}

// Destructor does nothing as no dynamic memory allocation is used
Food::~Food()
{
    // No cleanup required as no heap memory is allocated
}

// Generates a valid food position on the board, avoiding the player
void Food::generateFood(objPosArrayList* blockOff)
{
    const char foodSymbol = 'X';  // Food symbol to be placed
    bool foodPlaced = false;      // Flag to check if the food is successfully placed

    srand(time(NULL));  // Initialize the random seed

    while (!foodPlaced) {
        // Generate random coordinates within the grid
        int randX = rand() % 29 + 1;
        int randY = rand() % 14 + 1;

        foodPos.pos->x = randX;
        foodPos.pos->y = randY;

        // Check for overlap with any player block
        if (!isOverlapWithPlayer(blockOff)) {
            foodPos.symbol = foodSymbol;  // Assign food symbol if no overlap
            foodPlaced = true;  // Successfully placed food
        }
    }
}

// Checks if the generated food position overlaps with any player's position
bool Food::isOverlapWithPlayer(objPosArrayList* blockOff)
{
    int blockCount = blockOff->getSize();

    for (int i = 0; i < blockCount; ++i) {
        objPos currentBlock = blockOff->getElement(i);
        if (currentBlock.pos->x == foodPos.pos->x && currentBlock.pos->y == foodPos.pos->y) {
            return true;  // Overlap detected
        }
    }

    return false;  // No overlap
}

// Returns the position of the food
objPos Food::getFoodPos() const
{
    return foodPos;
}


