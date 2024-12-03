#include "Player.h"
#include "MacUILib.h"
#include "objPosArrayList.h"
#include "Food.h"


Player::Player(GameMechs* thisGMRef, Food* foodRef)
{
    mainGameMechsRef = thisGMRef;
    theFood = foodRef;
    currentDirection = STOP;
    
    // more actions to be included
    playerPosList = new objPosArrayList();
    //setting the head position and character
    objPos headPos(thisGMRef->getBoardSizeX() / 2, thisGMRef->getBoardSizeY() / 2, '*');
    //inserting head at the beginning of the playerlist
    playerPosList->insertHead(headPos);
    
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList; // x,y,symbol through value
}

void Player::updatePlayerDir()
{
    // Get the input (e.g., WASD or arrow keys)
    char input = mainGameMechsRef->getInput();
    
    if (input != 0) {  // If there's an input (not 0)
        switch(input)
        {                       
            case 'w': // Move UP
            case 'W':
                currentDirection = UP;
                break;

            case 's': // Move DOWN
            case 'S':
                currentDirection = DOWN;
                break;

            case 'a': // Move LEFT
            case 'A':
                currentDirection = LEFT;
                break;

            case 'd': // Move RIGHT
            case 'D':
                currentDirection = RIGHT;
                break;
            
            // Add other cases here if you want additional functionality
        } 
    }     
}


void Player::movePlayer()
{
    objPos currentPos = playerPosList->getHeadElement();
    objPos newPos = currentPos;
    // PPA3 Finite State Machine logic
    switch(currentDirection)
    
        {
            case UP:  //implenting wraparound and matrix increase and decreasing.
                newPos.pos->y--;
                if (newPos.pos->y == 0)
                {
                    newPos.pos->y = mainGameMechsRef -> getBoardSizeY()-1;
                }
                break;
                
            case DOWN:
                newPos.pos->y++;
                if (newPos.pos->y==mainGameMechsRef -> getBoardSizeY())
                {
                    newPos.pos->y = 1;
                }
                break;

            case LEFT:
                newPos.pos->x--;
                if (newPos.pos->x==0)
                {
                    newPos.pos->x=(mainGameMechsRef->getBoardSizeX()-1);
                }
                break;

            case RIGHT:
                newPos.pos->x++;
                if (newPos.pos->x==(mainGameMechsRef->getBoardSizeX()))
                {
                    newPos.pos->x = 1;
                }
                break;
            case STOP:
            default:
                break;
        }


    // Check food consume
    if (checkFoodConsumption()){

        increasePlayerLength();
        theFood->generateFood(playerPosList);
        mainGameMechsRef ->incrementScore();


    }
    // Add new head position and remove the tail
    playerPosList->insertHead(newPos);
    //playerPosList->removeTail();
    playerPosList->removeTail();
    
    checkSelfCollision();
}

// More methods to be added
char Player::getDirection()
{
    switch (currentDirection)
    {
        case UP:
            MacUILib_printf("UP\n");
            break;
        case DOWN:
            MacUILib_printf("DOWN\n");
            break;
        case LEFT:
            MacUILib_printf("LEFT\n");
            break;
        case RIGHT:
            MacUILib_printf("RIGHT\n");
            break;
        default:
            MacUILib_printf("STOP\n");
            break;
    };
} 

bool Player:: checkFoodConsumption ()
{
    //getting the head and food position
    objPos headPos = playerPosList->getHeadElement();
    objPos foodPos = theFood->getFoodPos();

    //checking if the head position is equal to the food position
    if (headPos.pos-> x == foodPos.pos->x && headPos.pos->y == foodPos.pos->y){
        return true;
    }
    return false;
}
void Player:: increasePlayerLength ()
{
    objPos lastPos = playerPosList->getTailElement();

    playerPosList->insertTail(lastPos);
   
}

bool Player:: checkSelfCollision ()
{
    // loop that checks if any segment of the player list is equal to the head element
    for (int i=1; i<playerPosList->getSize(); i++)
    {
        objPos headPos = playerPosList->getHeadElement();
        objPos listSeg = playerPosList->getElement(i);
        if(headPos.pos->x == listSeg.pos->x && headPos.pos->y == listSeg.pos->y)
        {
            mainGameMechsRef -> setLoseFlag();
            mainGameMechsRef -> setExitTrue();
        }
    }
}