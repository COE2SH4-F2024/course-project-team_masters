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

void Food::generateFood(objPos blockOff)
{
    do
    {
        foodPos.pos->x = 1 + (rand() % (mainGameMechsRef->getBoardSizeX() - 2));
        foodPos.pos->y = 1 + (rand() % (mainGameMechsRef->getBoardSizeY() - 2));
    } while (blockOff.pos == foodPos.pos);
    
}

objPos Food::getFoodPos() const
{
    return foodPos;
}