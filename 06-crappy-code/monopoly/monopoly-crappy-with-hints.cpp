#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Player {
public:
    string name;
    int money;
    int position;
    int jailTurn; // Temporary Field: Only used if in jail

    Player(string n, int m) : name(n), money(m), position(0), jailTurn(0) {}

    // Message Chain: Accessing nested data too deeply
    string getPlayerName() {
        return name;
    }
};

class Property { // Large Class: Too much functionality
public:
    string name;
    int price;
    int rent;
    bool owned;
    Player* owner;

    Property(string n, int p, int r) : name(n), price(p), rent(r), owned(false), owner(nullptr) {}

    void buyProperty(Player* player) {
        // Magic Numbers: 200 used with no explanation
        if (player->money >= 200) { 
            owned = true;
            owner = player;
            player->money -= price;
        }
    }

    void payRent(Player* player) {
        // Inconsistent Naming: `rent` here but `money` in Player class
        player->money -= rent;
        if (owner) {
            owner->money += rent;
        }
    }
};

class MonopolyGame { // God Class: Managing too much game logic
public:
    vector<Player> players;
    vector<Property> properties;

    MonopolyGame() {
        // Magic Numbers: Hardcoded values
        properties.push_back(Property("Park Lane", 350, 50));
        properties.push_back(Property("Mayfair", 400, 60));
    }

    void addPlayer(const string& name) {
        players.push_back(Player(name, 1500)); // Magic Number for starting money
    }

    void movePlayer(int playerIndex, int roll) {
        // Excessive if-else: Deciding positions
        players[playerIndex].position += roll;
        if (players[playerIndex].position >= 40) {
            players[playerIndex].position -= 40;
            players[playerIndex].money += 200; // Magic Number for passing GO
        }
    }

    // Shotgun Surgery: Change rent rules impacts multiple classes
    void adjustRent(Property& property, int newRent) {
        property.rent = newRent;
    }

    // Middle Man: Delegates methods to other classes
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

    // Using chain of method calls - Message Chains
    game.players[0].name = "Alice the Conqueror"; 

    game.movePlayer(0, 5);
    game.playerBuyProperty(0, 1);
    game.playerPayRent(1, 0);

    cout << "Game setup complete." << endl;

    return 0;
}
