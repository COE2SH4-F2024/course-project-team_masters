#include "Player.h"


Player::Player(GameMechs* thisGMRef, Food* thisFoodRef)
{
    mainFoodRef = thisFoodRef;
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included 
    playerPosList = new objPosArrayList();
    //Make it start in the center
    objPos headPos(mainGameMechsRef->getBoardSizeX() / 2 ,mainGameMechsRef->getBoardSizeY() / 2 , '*');
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
    return playerPosList;

}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic    
    char input = mainGameMechsRef->getInput();

    switch(input)
        {          
            case ' ':
            {
                mainGameMechsRef->setExitTrue();
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

    objPos temp = playerPosList->getHeadElement();

    if(myDir == LEFT)
    {
        temp.pos->x--;
        if (temp.pos->x== 0)
        {
            temp.pos->x= mainGameMechsRef->getBoardSizeX() - 2;
        }
    }
    else if(myDir == RIGHT)
    {
        temp.pos->x++;
        if (temp.pos->x == mainGameMechsRef->getBoardSizeX() - 1)
        {
            temp.pos->x = 1;
        }
    }
    else if(myDir == UP)
    {
        temp.pos->y--;
        if (temp.pos->y == 0)
        {
            temp.pos->y = mainGameMechsRef->getBoardSizeY() - 2;
        }
    }
    else if(myDir == DOWN)
    {
        temp.pos->y++;
        if (temp.pos->y == mainGameMechsRef->getBoardSizeY() - 1)
        {
            temp.pos->y = 1;
        }
    }

    if(myDir != STOP)
    {
        playerPosList->insertHead(temp);
        playerPosList->removeTail();//change once we do colission stuff
    }
    
}

// More methods to be added

bool Player::isPosInList(int xPos , int yPos)
{
    for(int i = 0; i < playerPosList->getSize(); i++)
    {
        if(playerPosList->getElement(i).pos->x == xPos && playerPosList->getElement(i).pos->y == yPos)
        {
            return true;
        }
    }
    return false;
}

char Player::getSymAtPos(int xPos , int yPos)
{
    for(int i = 0; i < playerPosList->getSize(); i++)
    {
        if(playerPosList->getElement(i).pos->x == xPos && playerPosList->getElement(i).pos->y == yPos)
        {
            return playerPosList->getElement(i).symbol;
        }
    }
    return ' ';
}

bool Player::checkFoodConsumption()
{
    if(playerPosList->getHeadElement().getObjPos().pos->x == mainFoodRef->getFoodPos().pos->x && playerPosList->getHeadElement().getObjPos().pos->y == mainFoodRef->getFoodPos().pos->y)
    {
        return true;
    }
    return false;
}

void Player::increasePlayerLength()
{
    objPos object;
    object.symbol = '*';
    playerPosList->insertTail(object);
}
