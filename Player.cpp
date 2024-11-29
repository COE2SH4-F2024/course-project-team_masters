#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included 
    playerPos.symbol = '*';
    //Make it start in the center
    playerPos.pos = new Pos();
    playerPos.pos->x = mainGameMechsRef->getBoardSizeX() / 2;
    playerPos.pos->y = mainGameMechsRef->getBoardSizeY() / 2;
}


Player::~Player()
{
    // delete any heap members here
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;

}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic    
    char input = mainGameMechsRef->getInput();

    switch(input)
        {                      
            case ' ':  // exit
            {
                myDir = STOP;
                break;
            }
            case 'w':
            case 'W':
            {
                if(myDir == RIGHT || myDir == LEFT || myDir == STOP)
                {
                    myDir = UP;
                }
                break;
            }

            case 's':
            case 'S':
            {
                if(myDir == RIGHT || myDir == LEFT || myDir == STOP)
                {
                    myDir = DOWN;
                }
                break;
            }

            case 'a':
            case 'A':
            {
                if(myDir == UP || myDir == DOWN || myDir == STOP)
                {
                    myDir = LEFT;
                }
                break;
            }

            case 'd':
            case 'D':
            {
                if(myDir == UP || myDir == DOWN || myDir == STOP)
                {
                    myDir = RIGHT;
                }
                break;
            }
            default:
                break;
        }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    if(myDir == LEFT)
    {
        playerPos.pos->x--;
        if (playerPos.pos->x== 0)
        {
            playerPos.pos->x= mainGameMechsRef->getBoardSizeX() - 2;
        }
    }
    else if(myDir == RIGHT)
    {
        playerPos.pos->x++;
        if (playerPos.pos->x == mainGameMechsRef->getBoardSizeX() - 1)
        {
            playerPos.pos->x = 1;
        }
    }
    else if(myDir == UP)
    {
        playerPos.pos->y--;
        if (playerPos.pos->y == 0)
        {
            playerPos.pos->y = mainGameMechsRef->getBoardSizeY() - 2;
        }
    }
    else if(myDir == DOWN)
    {
        playerPos.pos->y++;
        if (playerPos.pos->y == mainGameMechsRef->getBoardSizeY() - 1)
        {
            playerPos.pos->y = 1;
        }
    }
    else if(myDir == STOP)
    {
        //exit
    }
}

// More methods to be added