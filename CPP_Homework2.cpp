#include <iostream>
#include <vector>
#include <string>

struct Player {
    std::string name;
    int clan;
    int health;
    int damage;
    Player(std::string InName, int InClan, int InHealth, int InDamage) {
        name = InName;
        clan = InClan;
        health = InHealth;
        damage = InDamage;
    }
};

std::vector<Player> lobby;

void addPlayer(const std::string& name, int clan, int health, int damage) {
    lobby.push_back(Player( name, clan, health, damage ));
}

void removePlayer(const std::string& name, int clan) {
    lobby.erase(std::remove_if(lobby.begin(), lobby.end(), [&](const Player& player) {
        return player.name == name && player.clan == clan;
        }));
}

void startBattle() {
    int totalHealthClan0 = 0, totalDamageClan0 = 0;
    int totalHealthClan1 = 0, totalDamageClan1 = 0;

    for (const Player& player : lobby) {
        if (player.clan == 0) {
            totalHealthClan0 += player.health;
            totalDamageClan0 += player.damage;
        }
        else {
            totalHealthClan1 += player.health;
            totalDamageClan1 += player.damage;
        }
    }

    std::cout << "Clan 0 - Health: " << totalHealthClan0 << ", Damage: " << totalDamageClan0 << std::endl;
    std::cout << "Clan 1 - Health: " << totalHealthClan1 << ", Damage: " << totalDamageClan1 << std::endl;

    if (totalDamageClan0 >= totalHealthClan1 && totalDamageClan1 >= totalHealthClan0) {
        std::cout << "Draw" << std::endl;
    }
    else if (totalDamageClan0 >= totalHealthClan1) {
        std::cout << "Clan 0 wins" << std::endl;
    }
    else if (totalDamageClan1 >= totalHealthClan0) {
        std::cout << "Clan 1 wins" << std::endl;
    }
}

int main() {
    int command;
    std::cout << "Enter command(0 - addPlayer, 1 - removePLayer, 2 - startBattle): \n";
    while (std::cin >> command) 
    {

        if (command == 0) 
        {
            std::cout << "Enter player's name: \n";
            std::string name;
            int clan, health, damage;
            std::cin >> name;
            std::cout << "Enter player's clan(0 or 1): \n";
            std::cin >> clan;
            std::cout << "Enter player's health: \n";
            std::cin >> health;
            std::cout << "Enter player's damage: \n";
            std::cin >> damage;
            addPlayer(name, clan, health, damage);
            std::cout << "Added player:" << name << std::endl;
            std::cout << "Enter command(0 - addPlayer, 1 - removePLayer, 2 - startBattle): \n";
        }
        else if (command == 1) 
        {
            std::cout << "Enter player's name to remove from battle: \n";
            std::string name;
            int clan;
            std::cin >> name;
            std::cout << "Enter player's clan to remove from battle(0 or 1): \n";
            std::cin >> clan;
            removePlayer(name, clan);
            std::cout << "Removed player :" << name << std::endl;
            std::cout << "Enter command(0 - addPlayer, 1 - removePLayer, 2 - startBattle): \n";
        }
        else if (command == 2) {
            startBattle();
            break;
        }
    }
    return 0;
}