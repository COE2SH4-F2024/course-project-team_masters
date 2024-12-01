#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

Player* myPlayer;
GameMechs* myGM;
Food* myFood;


int main(void)
{

    Initialize();

    while(exitFlag == false)  
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

    srand(time(NULL));

    myGM = new GameMechs();
    myFood = new Food(myGM);
    myPlayer = new Player(myGM , myFood);
    
    myFood->generateFood(myPlayer->getPlayerPos());
    exitFlag = false;
}

void GetInput(void)
{
    myPlayer->updatePlayerDir();
    if(myGM->getExitFlagStatus() == true)
    {
        exitFlag = true;
    }
}

void RunLogic(void)
{
    myPlayer->movePlayer();
    if(myPlayer->checkFoodConsumption() == true)
    {
        myPlayer->increasePlayerLength();
        myFood->generateFood(myPlayer->getPlayerPos());
        myGM->incrementScore();
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

   
    objPos foodPos = myFood->getFoodPos();


    //MacUILib_printf("Player [x,y] = [%d, %d] %c" , playerPos.pos->x , playerPos.pos->y , playerPos.symbol); 
    //MacUILib_printf("\n");

    int i, j;
    for(i = 0; i < myGM->getBoardSizeY(); i++)//should we do border lim x and y?
    {
        for(j = 0; j < myGM->getBoardSizeX() ; j++)
        {
            if(i == 0 || i == myGM->getBoardSizeY() - 1 || j == 0 || j == myGM->getBoardSizeX() - 1)
            {
                MacUILib_printf("#");
            }
            else if(myPlayer->isPosInList(j,i) == true)
            {
                MacUILib_printf("%c", myPlayer->getSymAtPos(j,i));
            }
            else if(i == foodPos.pos->y && j == foodPos.pos->x)
            {
                MacUILib_printf("%c", foodPos.symbol);
            }
            else
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("\n");
    MacUILib_printf("Current Score: %d" , myGM->getScore());
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    delete myPlayer;
    delete myFood;
    delete myGM;
    MacUILib_uninit();
}
