#include "Player.h"

Player::Player(std::string name)
    :Creature(name, '@', PLAYER_START_HEALTH, PLAYER_START_DAMAGE, PLAYER_START_GOLD)
{}

size_t Player::getLevel() const{
    return m_level;
}

void Player::levelUp(){
    ++m_level;
    ++m_damage;
}

bool Player::hasWon() const{
    return m_level >= 20;
}