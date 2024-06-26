#include "Creature.h"

Creature::Creature(std::string name, char symbol, int health, int damage, int gold)
    :m_name(name), m_symbol(symbol), m_health(health), m_damage(damage), m_gold(gold)
{}

const std::string& Creature::getName() const{
    return m_name;
}

char Creature::getSymbol() const{
    return m_symbol;
}

int Creature::getHealth() const{
    return m_health;
}

int Creature::getDamage() const{
    return m_damage;
}

int Creature::getGold() const{
    return m_gold;
}

void Creature::reduceHealth(int damage){
    m_health -= damage;
}

bool Creature::isDead() const{
    return m_health <= 0;
}

void Creature::addGold(int gold){
    m_gold += gold;
}