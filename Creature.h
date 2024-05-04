#pragma once
#include <iostream>

class Creature{
    public:
    Creature(std::string name, char symbol, int health, int damage, int gold);

    const std::string& getName() const;

    char getSymbol() const;

    int getHealth() const;

    int getDamage() const;

    int getGold() const;

    void reduceHealth(int damage);

    bool isDead() const;

    void addGold(int gold);

    protected:
    std::string m_name;
    char m_symbol;
    int m_health;
    int m_damage;
    int m_gold;
};