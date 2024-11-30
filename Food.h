#ifndef FOOD_H
#define FOOD_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Food
{
    private:
        objPos foodPos;
        GameMechs* mainGameMechsRef;
    public:
        Food(GameMechs* mainGameMechsRef);
        ~Food();

        void generateFood(objPos blockOff);
        objPos getFoodPos() const;
};

#endif