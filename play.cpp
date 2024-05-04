#include <iostream>
#include <cstdlib> //rand(), srand()
#include <ctime> //time()
#include "Monster.h"
#include "Player.h"

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]{
    {"dragon", 'D', 20, 4, 100},
    {"orc", 'o', 4, 2, 25},
    {"slime", 's', 1, 1, 10}
};

Player createPlayer(){
    std::cout << "Enter your name ";
    std::string name;
    std::cin >> name;
    return Player(name);
}

char choice(){
    char c;
    do{
        std::cout << "(R)un or (F)ight: ";
        std::cin >> c;
        c = toupper(c);
    }while (c != 'F' && c != 'R');

    return c;
}

void attackMonster(Player& player, Monster& monster){
    std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage" << std::endl;
    monster.reduceHealth(player.getDamage());
    if (monster.isDead()){
        std::cout << "You killed the " << monster.getName() << "." << std::endl;
        player.levelUp();
        std::cout << "You are now level " << player.getLevel() << "." << std::endl;
        std::cout << "Your found " << monster.getGold() << " gold." << std::endl << std::endl;
        player.addGold(monster.getGold());
    }
}

void attackPlayer(Player& player, Monster& monster){
    std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage." << std::endl;
    player.reduceHealth(monster.getDamage());
}

bool fightMonster(Player& player, Monster& monster){
    if (choice() == 'R'){
        if (getRandomNumber(0, 1)){
            std::cout << "You successfully run." << std::endl << std::endl;
            return false;
        }
        attackPlayer(player, monster);
    }
    else{
        attackMonster(player, monster);
        if (!monster.isDead())
            attackPlayer(player, monster);
    }

    return true;
}

int main(){
    srand(static_cast<size_t>(time(0)));
    rand();

    Player player = createPlayer();

    do{
        Monster monster = Monster::getRandomMonster();
        bool flag = true;
        std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ")" << std::endl;

        while (!player.isDead() && !monster.isDead() && flag){
            flag = fightMonster(player, monster);
        }
    } while (!player.isDead() && !player.hasWon());

    if (player.isDead()){
        std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold." << std::endl;
        std::cout << "Too bad you can't take it with you!" << std::endl;
    }
    else{
        std::cout << "You won!!!" << std::endl;
        std::cout << "You achieve " << player.getLevel() << " level and with " << player.getGold() << " gold." << std::endl;
    }

    return 0;
}