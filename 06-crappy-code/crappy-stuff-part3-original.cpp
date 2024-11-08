#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Coffee
{
public:
    int type; // Coffee type 
    bool isHot;
    int s; // Size

    Coffee() { 
        type = 1; // Default to "Espresso"
        isHot = true; 
        s = 2; // Medium size
    }

    void printDetails() {
        std::cout << "Coffee Type: " << type << ", Size: " << s << ", Hot: " << isHot << std::endl;
    }
};

class CoffeeMachine 
{
public:
    int beans; // Amount of beans in grams
    int water; // Water level in ml
    bool isClean;

    CoffeeMachine() {
        beans = 100;
        water = 500;
        isClean = true;
    }

    void makeCoffee(Coffee& coffee) {
        if (beans > 10 && water > 50) {
            std::cout << "Making coffee..." << std::endl;
            beans -= 10;
            water -= 50;
            coffee.printDetails();
        } else {
            std::cout << "Not enough beans or water!" << std::endl;
        }
    }

    void refill() { 
        std::cout << "Refilling beans and water..." << std::endl;
        beans = 100;
        water = 500;
    }

    void clean() { 
        std::cout << "Cleaning coffee machine..." << std::endl;
        isClean = true;
    }

    void status() { 
        std::cout << "Beans: " << beans << "g, Water: " << water << "ml, Clean: " << isClean << std::endl;
    }
};

class User 
{
public:
    void wantsCoffee(CoffeeMachine* machine) { 
        Coffee coffee; // Default coffee
        std::cout << "User wants coffee." << std::endl;
        machine->makeCoffee(coffee); // Making coffee with machine
    }

    void addMilk() {
        std::cout << "Adding milk..." << std::endl;
    }

    void addSugar() { 
        std::cout << "Adding sugar..." << std::endl;
    }

    void drink() { 
        std::cout << "Drinking coffee..." << std::endl;
    }
};

int main() {
    CoffeeMachine cm; 
    User u; 

    cm.status(); // Status check before making coffee
    u.wantsCoffee(&cm); // User "wants" coffee
    u.addMilk(); // Adding milk in a vacuum
    u.addSugar(); // Adding sugar with no actual effect
    u.drink(); // Drinking imaginary coffee

    cm.refill(); // Refilling the machine
    cm.clean(); // Cleaning the machine
    cm.status(); // Final status check

    return 0;
}
