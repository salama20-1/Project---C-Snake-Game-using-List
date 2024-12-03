#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"
#include "Food.h"



using namespace std;

#define DELAY_CONST 100000
int delay = 100000;

Player *myPlayer; // Gloabla pointer meant to instantiate a player object on heap
GameMechs *myGM; 
Food *myFood;

struct objPos myObj;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM-> getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs();
    myFood = new Food();
    myPlayer = new Player(myGM, myFood); // creating player object on the heap
    myFood -> generateFood(myPlayer->getPlayerPos());


}

void GetInput(void)
{
    myGM -> collectAsyncInput(myFood, myPlayer->getPlayerPos());
    // for debugging key of random food
}

void RunLogic(void)
{

    myPlayer -> updatePlayerDir();
    myPlayer -> movePlayer();
    myGM -> clearInput();
    //add movePlayer
    //add speed control

    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();  

    objPosArrayList* playerPos = myPlayer -> getPlayerPos(); // goes into copy assignement operator
    int playerSize = playerPos->getSize();
    objPos foodPos = myFood -> getFoodPos();

    int j, i, flag;

    for (i=0; i<= myGM ->getBoardSizeY();i++)
    {
        if (i==0 || i==myGM ->getBoardSizeY())
        {
            for (j=0; j<= myGM ->getBoardSizeX(); j++)
            {
                MacUILib_printf("#");
            }

            MacUILib_printf("\n");
            
        }

        else
        {
           for (j=0; j<= myGM ->getBoardSizeX(); j++)
            {
                flag = 0;
                for(int k=0; k<playerSize;k++){
                    objPos thisSeg = playerPos -> getElement(k);
                    if(thisSeg.pos->x == j && thisSeg.pos->y == i)
                    {

                        MacUILib_printf("%c", thisSeg.symbol);
                        flag = 1;
                        break;
                    }
                }
                
                if (flag ==0)
                {

                    if (j==0)
                    {
                        MacUILib_printf("#");
                    }
                    
                    else if (j==myGM ->getBoardSizeX())
                    {
                        MacUILib_printf("#");
                    }

                    /* else if ( playerPos.pos->x == j && playerPos.pos->y == i)
                    {
                        MacUILib_printf("%c", playerPos.symbol);
                    } */

                    else if ( foodPos.pos->x == j && foodPos.pos->y == i)
                    {
                        MacUILib_printf("%c", foodPos.symbol);
                    }

                    else 
                    {
                        MacUILib_printf(" ");
                    }
                }

            } 

            MacUILib_printf("\n");
            
        }


    }


    MacUILib_printf("\nCURRENT SCORE: %d\n", myGM->getScore());
    MacUILib_printf("FOOD POSITION: [%d, %d]\n", foodPos.pos->x, foodPos.pos->y);
    MacUILib_printf("Press ESC to exit the game.");
   
}

void LoopDelay(void)
{
    MacUILib_Delay(delay); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();  

    delete myPlayer;
    delete myGM;
    delete myFood;

    MacUILib_uninit();
}