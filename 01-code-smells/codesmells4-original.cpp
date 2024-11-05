#include <iostream>
#include <string>
using namespace std;

// Data Classes: Original
class UserData {
public:
    string name;
    int age;
    string email;
    string address;

    // Only getters and setters, no real behavior
    string getName() const { return name; }
    void setName(const string& n) { name = n; }
    int getAge() const { return age; }
    void setAge(int a) { age = a; }
    string getEmail() const { return email; }
    void setEmail(const string& e) { email = e; }
    string getAddress() const { return address; }
    void setAddress(const string& addr) { address = addr; }
};

// Refused Bequest: Original
class Animal {
public:
    virtual void makeSound() = 0;
    virtual void fly() {
        cout << "This animal can fly.\n";
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Bark!\n";
    }
    // Dog "inherits" fly(), but it doesn't make sense for a dog to fly
};
