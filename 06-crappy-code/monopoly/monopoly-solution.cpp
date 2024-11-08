#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Player {
public:
    string name;
    int money;
    int position;
    int jailTurn; 

    Player(string playerName, int initialMoney)
        : name(playerName), money(initialMoney), position(0), jailTurn(0) {}

    bool isInJail() const {
        return jailTurn > 0;
    }
};

class Property {
public:
    string name;
    int price;
    int rent;
    Player* owner;

    Property(string propertyName, int propertyPrice, int propertyRent) 
        : name(propertyName), price(propertyPrice), rent(propertyRent), owner(nullptr) {}

    void buy(Player& player) {
        if (player.money >= price) { // Uses property price instead of magic numbers
            owner = &player;
            player.money -= price;
            cout << player.name << " bought " << name << endl;
        } else {
            cout << player.name << " cannot afford " << name << endl;
        }
    }

    void chargeRent(Player& player) {
        if (owner && owner != &player) {
            player.money -= rent;
            owner->money += rent;
            cout << player.name << " paid " << rent << " in rent to " << owner->name << endl;
        }
    }
};

class MonopolyGame {
public:
    vector<unique_ptr<Player>> players;
    vector<unique_ptr<Property>> properties;

    MonopolyGame() {
        properties.push_back(make_unique<Property>("Park Lane", 350, 50));
        properties.push_back(make_unique<Property>("Mayfair", 400, 60));
    }

    void addPlayer(const string& playerName) {
        players.push_back(make_unique<Player>(playerName, 1500));
    }

    void movePlayer(Player& player, int roll) {
        player.position = (player.position + roll) % 40;
        if (player.position == 0) { // Passes GO if returns to start
            player.money += 200;
            cout << player.name << " passed GO and collected 200.\n";
        }
    }

    void conductTurn(Player& player, int roll) {
        movePlayer(player, roll);
        for (auto& property : properties) {
            if (property->name == "Park Lane" && player.position == 37) {
                property->chargeRent(player);
            }
        }
    }

    void gameLoop() {
        for (auto& player : players) {
            int roll = 7; // For example purposes; in reality, this would vary
            conductTurn(*player, roll);
        }
    }
};

int main() {
    MonopolyGame game;
    game.addPlayer("Alice");
    game.addPlayer("Bob");

    game.gameLoop();

    cout << "Game setup complete." << endl;
    return 0;
}
