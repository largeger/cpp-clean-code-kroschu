#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Data Clumps: Original
void printPersonDetails(const string& name, const string& street, const string& city, const string& state, const string& zip) {
    cout << "Name: " << name << "\nAddress: " << street << ", " << city << ", " << state << ", " << zip << "\n";
}

// Primitive Obsession: Original
class ProductOrder {
public:
    double price;
    int quantity;
    string currency;

    ProductOrder(double p, int q, const string& curr) : price(p), quantity(q), currency(curr) {}

    void printOrder() {
        cout << "Order: " << quantity << " items at " << currency << price << "\n";
    }
};

// Case Statements in Object-Oriented Code: Original
enum class ShapeType { CIRCLE, SQUARE, TRIANGLE };

class Shape {
public:
    ShapeType type;
    Shape(ShapeType t) : type(t) {}

    void draw() {
        switch (type) {
            case ShapeType::CIRCLE:
                cout << "Drawing a Circle\n";
                break;
            case ShapeType::SQUARE:
                cout << "Drawing a Square\n";
                break;
            case ShapeType::TRIANGLE:
                cout << "Drawing a Triangle\n";
                break;
        }
    }
};

// Parallel Inheritance: Original
class Animal {
public:
    virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
    void makeSound() override { cout << "Bark!\n"; }
};

class AnimalToy {
public:
    virtual void playSound() = 0;
};

class DogToy : public AnimalToy {
public:
    void playSound() override { cout << "Squeak Bark!\n"; }
};

// Lazy Class: Original
class DiscountManager {
public:
    DiscountManager() {}
    void applyDiscount(double amount) {
        if (amount > 100) cout << "Applying discount\n";
    }
};
