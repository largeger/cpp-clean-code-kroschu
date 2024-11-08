#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Player {
public:
    string name;
    int money;
    int position;
    int jailTurn; 

    Player(string n, int m) : name(n), money(m), position(0), jailTurn(0) {}

    string getPlayerName() {
        return name;
    }
};

class Property { 
public:
    string name;
    int price;
    int rent;
    bool owned;
    Player* owner;

    Property(string n, int p, int r) : name(n), price(p), rent(r), owned(false), owner(nullptr) {}

    void buyProperty(Player* player) {
        if (player->money >= 200) { 
            owned = true;
            owner = player;
            player->money -= price;
        }
    }

    void payRent(Player* player) {
        player->money -= rent;
        if (owner) {
            owner->money += rent;
        }
    }
};

class MonopolyGame { 
public:
    vector<Player> players;
    vector<Property> properties;

    MonopolyGame() {
        properties.push_back(Property("Park Lane", 350, 50));
        properties.push_back(Property("Mayfair", 400, 60));
    }

    void addPlayer(const string& name) {
        players.push_back(Player(name, 1500)); 
    }

    void movePlayer(int playerIndex, int roll) {
        
        players[playerIndex].position += roll;
        if (players[playerIndex].position >= 40) {
            players[playerIndex].position -= 40;
            players[playerIndex].money += 200; 
        }
    }


    void adjustRent(Property& property, int newRent) {
        property.rent = newRent;
    }


    void playerBuyProperty(int playerIndex, int propertyIndex) {
        properties[propertyIndex].buyProperty(&players[playerIndex]);
    }

    void playerPayRent(int playerIndex, int propertyIndex) {
        properties[propertyIndex].payRent(&players[playerIndex]);
    }
};

int main() {
    MonopolyGame game;
    game.addPlayer("Alice");
    game.addPlayer("Bob");

    game.players[0].name = "Alice the Conqueror"; 

    game.movePlayer(0, 5);
    game.playerBuyProperty(0, 1);
    game.playerPayRent(1, 0);

    cout << "Game setup complete." << endl;

    return 0;
}
