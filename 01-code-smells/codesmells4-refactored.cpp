#include <iostream>
#include <string>
using namespace std;

// Data Classes: Refactored
class UserDataRefactored {
private:
    string name;
    int age;
    string email;
    string address;

public:
    UserDataRefactored(const string& n, int a, const string& e, const string& addr)
        : name(n), age(a), email(e), address(addr) {}

    void printUserSummary() const {
        cout << "User: " << name << ", Age: " << age << "\n";
    }

    bool isAdult() const {
        return age >= 18;
    }
};

// Refused Bequest: Refactored
class AnimalBase {
public:
    virtual void makeSound() = 0;
};

class FlyingAnimal : public AnimalBase {
public:
    virtual void fly() const {
        cout << "This animal can fly.\n";
    }
};

class DogRefactored : public AnimalBase {
public:
    void makeSound() override {
        cout << "Bark!\n";
    }
};

class Bird : public FlyingAnimal {
public:
    void makeSound() override {
        cout << "Tweet!\n";
    }
};
