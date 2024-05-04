#include "Monster.h"

int getRandomNumber(int min, int max){
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

Monster::Monster(Type type)
    :Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health,
                monsterData[type].damage, monsterData[type].gold)
{}

Monster Monster::getRandomMonster(){
    return static_cast<Type>(getRandomNumber(0, MAX_TYPES - 1));
}