#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class CatObj // Cat!!! 
{
public:
    std::string nm; // name + remove comment // Name of cat 
    int wt; // weight, unit missing + remove comment // Cat's weight 
    int sleepTime; // sleepHours // Amount of sleep 

    CatObj() { // Default constructor
        nm = "Garfield";
        wt = 15; // magic number?
        sleepTime = 16; // Average hours a cat sleeps
    }

    void details() { // better name toString
        std::cout << "Name: " << nm << ", Weight: " << wt << " lbs, Sleep Time: " << sleepTime << " hrs" << std::endl;
    }
};

// 1. name: CatAction
// 2. SRP & ISP violated potentially
class CatAct 
{
public:
    void eat(int amount) { // what is amount? integrate amount into name of method
        std::cout << "Cat is eating " << amount << " servings." << std::endl;
    }

    void nap() {
        std::cout << "Cat is napping." << std::endl;
    }

    void chaseMice() {
        // unnecessary comment // Chase mice function
        std::cout << "Cat is chasing mice!" << std::endl;
    }

    void randomAction(CatObj* cat) { // unnecessary param, magic numbers, long method, 
        int action = std::rand() % 3;
        if (action == 0) {
            eat(2);
        } else if (action == 1) {
            nap();
        } else {
            chaseMice();
        }
    }
};

class Food 
{
public:
    std::vector<std::string> meals; // private?

    void addMeal(std::string meal) {
        meals.push_back(meal); 
    }

    void displayMeals() { 
        std::cout << "Meals eaten: ";
        for (auto& meal : meals) {
            std::cout << meal << ", ";
        }
        std::cout << std::endl;
    }
};

class CatKeeper // Owner?!?
{
public:
    void doSomethingWithCat(CatObj* cat, CatAct* act) { // Dependency Inversion principle!
        std::cout << "Doing something with cat..." << std::endl;
        act->randomAction(cat);
    }

    void feedCat(CatObj* cat, Food* food) { // Dependency Inversion principle!
        std::cout << cat->nm << " is being fed." << std::endl;
        food->addMeal("Salmon");
    }
};

int main() {
    std::srand(std::time(0)); // Seed for randomness

    CatObj c; 
    CatAct ca; 
    Food fd; 
    CatKeeper ck; 

    ck.feedCat(&c, &fd); // Cat is being fed
    ck.doSomethingWithCat(&c, &ca); // Cat does random action
    fd.displayMeals(); // Shows meals eaten

    return 0;
}
