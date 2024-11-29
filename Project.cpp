#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"

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

    myGM = new GameMechs();
    myPlayer = new Player(myGM);
    exitFlag = false;
}

void GetInput(void)
{
    myPlayer->updatePlayerDir();
}

void RunLogic(void)
{
    myPlayer->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

    objPos playerPos = myPlayer->getPlayerPos();

    MacUILib_printf("Player [x,y] = [%d, %d] %c" , playerPos.pos->x , playerPos.pos->y , playerPos.symbol); 
    MacUILib_printf("\n");

    int i, j;
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 20; j++)
        {
            if(i == 0 || i == 9 || j == 0 || j == 19)
            {
                MacUILib_printf("#");
            }
            else if(i == playerPos.pos->y && j == playerPos.pos->x)
            {
                MacUILib_printf("%c", playerPos.symbol);
            }
            else
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    delete myPlayer;
    MacUILib_uninit();
}
