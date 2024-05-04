#pragma once
#include "Creature.h"
#define PLAYER_START_DAMAGE 1
#define PLAYER_START_HEALTH 100
#define PLAYER_START_GOLD 0

class Player : public Creature{
    private:
    size_t m_level = 1;

    public:
    Player(std::string name);

    size_t getLevel() const;

    void levelUp();

    bool hasWon() const;
};