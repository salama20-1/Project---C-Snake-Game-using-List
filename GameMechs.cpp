#include "GameMechs.h"
#include "MacUILib.h"
#include "Food.h"

// default constructor
GameMechs::GameMechs()
{
    // initialize variables
    input = 0;              // no initial input
    exitFlag = false;       
    loseFlag = false;       
    score = 0;              // score starts at 0

    boardSizeX = 30;        // Default board width
    boardSizeY = 15;        // Default board height
}

// parameterized constructor with custom board size
GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;              
    exitFlag = false;       
    loseFlag = false;       
    score = 0;              

    boardSizeX = boardX;    
    boardSizeY = boardY;    
}

// destructor (no dynamic memory management required yet)
GameMechs::~GameMechs()
{
    // no resources on heap to release, so destructor stays empty for now
}

// get the exit flag status
bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

// get the lose flag status (whether the player lost)
bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}

// collect asynchronous input from the user
void GameMechs::collectAsyncInput(Food* myFood, objPosArrayList* blockOff)
{
    // check if a key was pressed
    if (MacUILib_hasChar()) {
        input = MacUILib_getChar();  // Store the input character
    }

    // If ESC key is pressed, exit the game
    if (input == 27) { 
        setExitTrue(); // Set exit flag
    }
} 

// get the latest user input
char GameMechs::getInput()
{
    return input;
}

// get the current score
int GameMechs::getScore() const
{
    return score;
}

// increment the score by a specified value
void GameMechs::incrementScore(int value)
{
    score += value;  // add value to current score
}

// get board's width (X)
int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

// get board's height (Y)
int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}

// set exit flag to true (indicates the game should exit)
void GameMechs::setExitTrue()
{
    MacUILib_Delay(1000000);  // delay to allow for game state update
    exitFlag = true;          // set exit flag to true
}

// set the lose flag (indicates the player has lost the game)
void GameMechs::setLoseFlag()
{
    loseFlag = true;          // set lose flag to true
    
    // if lose flag is set, print game over message
    if (getLoseFlagStatus() == true){
        MacUILib_printf("\nGAME OVER!!\n");  // print game over message
        MacUILib_Delay(1000000);  // delay for visual effect
    }
}

// set the user input manually (useful in specific cases)
void GameMechs::setInput(char this_input)
{
    if (MacUILib_hasChar()) {
        input = this_input;  
    }
}

// clear the stored input (reset input to 0)
void GameMechs::clearInput()
{
    input = 0;  // reset input to 0 (no input)
}
