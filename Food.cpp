#include "Food.h"

Food::Food(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;

    foodBucket = new objPosArrayList();

    objPos firstFood(-10,-10,'o');
    foodBucket->insertHead(firstFood);

}

Food::~Food()
{
    // delete heap members
    delete foodBucket;
}

void Food::generateFood(objPosArrayList* blockOff , int numFood)
{
    //Remove all other foods
    while(foodBucket->getSize() > 0)
    {
        foodBucket->removeHead();
    }
    

    for(int k = 0; k < numFood; k++)
    {
        bool taken;
        //Initialize head position
        objPos temp;
        temp.symbol = 'o';
        do
        {
            temp.pos->x = 1 + (rand() % (mainGameMechsRef->getBoardSizeX() - 2));
            temp.pos->y = 1 + (rand() % (mainGameMechsRef->getBoardSizeY() - 2));
            temp.symbol = 'o';

            taken = false;

            //Check if taken by other food
            for(int j = 0; j < foodBucket->getSize(); j++)
            {
                if(foodBucket->getElement(j).pos->x == temp.pos->x && foodBucket->getElement(j).pos->y == temp.pos->y)
                {
                    taken = true;
                    break;
                }
            }

            //Check if taken by player , only checks if not already taken
            if(!taken)
            {
                for(int i = 0; i < blockOff->getSize(); i++)
                {
                    if(blockOff->getElement(i).pos->x == temp.pos->x && blockOff->getElement(i).pos->y == temp.pos->y) 
                    {
                        taken = true;
                        break;
                    }   
                }
            }
        } while (taken == true);

        foodBucket->insertHead(temp);

    }
    
}

void Food::generateSpecialFood(objPosArrayList* blockOff)
{
    bool taken;
        //Initialize head position
        objPos temp;
        temp.symbol = 'x';
        do
        {
            temp.pos->x = 1 + (rand() % (mainGameMechsRef->getBoardSizeX() - 2));
            temp.pos->y = 1 + (rand() % (mainGameMechsRef->getBoardSizeY() - 2));
            temp.symbol = 'x';

            taken = false;

            //Check if taken by other food
            for(int j = 0; j < foodBucket->getSize(); j++)
            {
                if(foodBucket->getElement(j).pos->x == temp.pos->x && foodBucket->getElement(j).pos->y == temp.pos->y)
                {
                    taken = true;
                    break;
                }
            }

            //Check if taken by player , only checks if not already taken
            if(!taken)
            {
                for(int i = 0; i < blockOff->getSize(); i++)
                {
                    if(blockOff->getElement(i).pos->x == temp.pos->x && blockOff->getElement(i).pos->y == temp.pos->y) 
                    {
                        taken = true;
                        break;
                    }   
                }
            }
        } while (taken == true);

        //1/5 chance of appearing
        if((1 + rand() % 5) == 3)
        {
            foodBucket->insertHead(temp);
        }
        
}
objPosArrayList* Food::getFoodPos() const
{
    return foodBucket;
}

bool Food::isPosInList(int xPos , int yPos)
{
    for(int i = 0; i < foodBucket->getSize(); i++)
    {
        if(foodBucket->getElement(i).pos->x == xPos && foodBucket->getElement(i).pos->y == yPos)
        {
            return true;
        }
    }
    return false;
}

char Food::getSymAtPos(int xPos , int yPos)
{
    for(int i = 0; i < foodBucket->getSize(); i++)
    {
        if(foodBucket->getElement(i).pos->x == xPos && foodBucket->getElement(i).pos->y == yPos)
        {
            return foodBucket->getElement(i).symbol;
        }
    }
    return ' ';
}

