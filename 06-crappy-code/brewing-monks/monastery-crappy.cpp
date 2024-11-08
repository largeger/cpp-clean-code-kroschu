#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Monk {
public:
    string name;
    int age;
    string role;

    Monk(string n, int a, string r) : name(n), age(a), role(r) {}
};


class Library {
public:
    void catalog() {
        cout << "Cataloging ancient scrolls...\n";
    }
};


class MonasteryManager {
public:
    vector<Monk> monks;
    Library library;


    void printMonkInfo(Monk monk) {
        cout << monk.name << " is " << monk.age << " years old and works as a " << monk.role << ".\n";
    }


    void printAllMonks() {
        cout << "Monks in the monastery:\n";
        for (auto& monk : monks) {
            cout << monk.name << "\n";
        }
    }

    void printElderMonks() {
        cout << "Elder monks:\n";
        for (auto& monk : monks) {
            if (monk.age > 70) {
                cout << monk.name << "\n";
            }
        }
    }

    void manageBrewery(int monksAvailable, int beerBottles) {
        if (monksAvailable < 1) {
            cout << "Not enough monks to brew beer.\n";
            return;
        }
        if (beerBottles > 500) {
            cout << "Too much beer! The brewery is overflowing!\n";
            return;
        }
        if (monksAvailable >= 3) {
            cout << "Three monks are brewing beer...\n";
        }
        if (monksAvailable == 2) {
            cout << "Two monks are brewing beer.\n";
        } else if (monksAvailable == 1) {
            cout << "One monk is brewing beer.\n";
        }
        cout << "Beer brewing process completed.\n";
    }

    void manageInventory(string item, int quantity) {
        if (item == "cheese" && quantity > 0) {
            cout << "Storing " << quantity << " blocks of cheese.\n";
        } else if (item == "herbs" && quantity > 0) {
            cout << "Storing " << quantity << " bundles of herbs.\n";
        } else if (item == "beer" && quantity > 0) {
            cout << "Storing " << quantity << " bottles of beer.\n";
        } else {
            cout << "Invalid item or quantity.\n";
        }
    }

    void monitorAirQuality(int days) {
        if (days > 100) {
            cout << "Monitoring air quality over " << days << " days is too excessive.\n";
        }
    }

    void giveMonkRaise(Monk& monk) {
        if (monk.role == "Brewmaster") {
            monk.age += 1;
            cout << monk.name << " received a raise for his brewmaster skills!\n";
        }
    }

    void performDuties(const Monk& monk) {
        if (monk.role == "Brewmaster") {
            cout << monk.name << " is brewing beer.\n";
        } else if (monk.role == "Cheesemaker") {
            cout << monk.name << " is making cheese.\n";
        } else if (monk.role == "Herbalist") {
            cout << monk.name << " is gathering herbs.\n";
        }
    }
};

int main() {
    MonasteryManager manager;
    manager.monks.push_back(Monk("Franz", 80, "Brewmaster"));
    manager.monks.push_back(Monk("Hans", 60, "Cheesemaker"));
    manager.monks.push_back(Monk("Karl", 40, "Herbalist"));

    manager.printAllMonks();
    manager.printElderMonks();
    manager.manageBrewery(3, 400);
    manager.manageInventory("beer", 300);
    manager.monitorAirQuality(150);
    manager.giveMonkRaise(manager.monks[0]);
    manager.performDuties(manager.monks[1]);

    return 0;
}
