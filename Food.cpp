#include "Food.h"

Food::Food(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;

    foodPos.symbol = 'o';

    foodPos.pos = new Pos();
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
        foodPos.pos->x = (rand() %mainGameMechsRef->getBoardSizeX()) + 1;
        foodPos.pos->y = (rand() %mainGameMechsRef->getBoardSizeY()) + 1;
    } while (blockOff.pos == foodPos.pos);
    
}

objPos Food::getFoodPos() const
{
    return foodPos;
}