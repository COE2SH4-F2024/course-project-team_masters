#ifndef FOOD_H
#define FOOD_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"


class Food
{
    private:
        //objPos foodPos;
        GameMechs* mainGameMechsRef;
        objPosArrayList* foodBucket;
    public:
        Food(GameMechs* mainGameMechsRef);
        ~Food();

        void generateFood(objPosArrayList* blockOff , int numFood);
        void generateSpecialFood(objPosArrayList* blockOff);
        objPosArrayList* getFoodPos() const;

        bool isPosInList(int xPos , int yPos);
        char getSymAtPos(int xPos , int yPos);
};

#endif