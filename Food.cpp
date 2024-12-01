#include "Food.h"

Food::Food(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;

    foodPos.symbol = 'o';

    
    foodPos.pos->x = -10;
    foodPos.pos->y = -10;
}

Food::~Food()
{
    // delete heap members
}

void Food::generateFood(objPosArrayList* blockOff)
{
    bool taken = true;
    do
    {
        foodPos.pos->x = 1 + (rand() % (mainGameMechsRef->getBoardSizeX() - 2));
        foodPos.pos->y = 1 + (rand() % (mainGameMechsRef->getBoardSizeY() - 2));

        for(int i = 0; i < blockOff->getSize(); i++)
        {
            if(foodPos.pos->x == blockOff->getElement(i).pos->x && foodPos.pos->y == blockOff->getElement(i).pos->y)
            {
                taken = true;
                break;
            }
            taken = false;
        }
    } while (taken == true);
    
}

objPos Food::getFoodPos() const
{
    return foodPos;
}