#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Monk {
public:
    string name;
    int age;
    string role;

    Monk(string n, int a, string r) : name(n), age(a), role(r) {}

    void printInfo() const { // Encapsulates the behavior
        cout << name << " is " << age << " years old and works as a " << role << ".\n";
    }

    bool isElder() const { // Adds meaningful behavior to Monk class
        return age > 70;
    }
};

// Avoids God Class by separating different functionalities
class Monastery {
public:
    vector<shared_ptr<Monk>> monks;

    void addMonk(shared_ptr<Monk> monk) {
        monks.push_back(monk);
    }

    void printAllMonks() {
        cout << "Monks in the monastery:\n";
        for (auto& monk : monks) {
            monk->printInfo(); // Avoids Feature Envy by using Monk’s method
        }
    }

    void printElderMonks() {
        cout << "Elder monks:\n";
        for (auto& monk : monks) {
            if (monk->isElder()) { // Reuses Monk’s isElder method
                cout << monk->name << "\n";
            }
        }
    }
};

class Brewery {
public:
    void brewBeer(int monksAvailable) {
        cout << monksAvailable << " monk(s) brewing beer...\n";
        cout << "Beer brewing process completed.\n";
    }
};

// Encapsulates inventory items to avoid Primitive Obsession
class InventoryItem {
public:
    string itemName;
    int quantity;

    InventoryItem(const string& name, int qty) : itemName(name), quantity(qty) {}

    void storeItem() const {
        cout << "Storing " << quantity << " units of " << itemName << ".\n";
    }
};

class Inventory {
public:
    void storeItem(const InventoryItem& item) {
        if (item.quantity > 0) {
            item.storeItem();
        } else {
            cout << "Invalid item quantity.\n";
        }
    }
};

class Duty {
public:
    virtual void performDuty() const = 0;
};

class BrewDuty : public Duty {
    string name;
public:
    BrewDuty(const string& monkName) : name(monkName) {}

    void performDuty() const override {
        cout << name << " is brewing beer.\n";
    }
};

class CheeseDuty : public Duty {
    string name;
public:
    CheeseDuty(const string& monkName) : name(monkName) {}

    void performDuty() const override {
        cout << name << " is making cheese.\n";
    }
};

int main() {
    auto monastery = make_shared<Monastery>();
    monastery->addMonk(make_shared<Monk>("Franz", 80, "Brewmaster"));
    monastery->addMonk(make_shared<Monk>("Hans", 60, "Cheesemaker"));
    monastery->addMonk(make_shared<Monk>("Karl", 40, "Herbalist"));

    monastery->printAllMonks();
    monastery->printElderMonks();

    Brewery brewery;
    brewery.brewBeer(3);

    Inventory inventory;
    inventory.storeItem(InventoryItem("beer", 300));

    BrewDuty brewDuty("Franz");
    CheeseDuty cheeseDuty("Hans");

    brewDuty.performDuty();
    cheeseDuty.performDuty();

    return 0;
}
