#pragma once
#include "Creature.h"

int getRandomNumber(int min, int max);


class Monster : public Creature{
    public:
    enum Type{
        DRAGON,
        ORC,
        SLIME,
        MAX_TYPES
    };

    struct MonsterData{
        std::string name;
        char symbol;
        int health;
        int damage;
        int gold;
    };

    static MonsterData monsterData[MAX_TYPES];

    Monster(Type type);

    static Monster getRandomMonster();
};