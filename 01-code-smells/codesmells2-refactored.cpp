#include <iostream>
#include <string>
#include <memory>
using namespace std;

// Data Clumps: Refactored
class Address {
public:
    string street, city, state, zipCode;

    Address(const string& s, const string& c, const string& st, const string& z) 
        : street(s), city(c), state(st), zipCode(z) {}
};

class Person {
public:
    string name;
    Address address;

    Person(const string& n, const Address& addr) : name(n), address(addr) {}

    void printDetails() {
        cout << "Name: " << name << "\nAddress: " << address.street << ", " << address.city 
             << ", " << address.state << ", " << address.zipCode << "\n";
    }
};

// Primitive Obsession: Refactored
class Money {
public:
    double amount;
    string currency;

    Money(double amt, const string& curr) : amount(amt), currency(curr) {}
};

class ProductOrderRefactored {
public:
    Money price;
    int quantity;

    ProductOrderRefactored(const Money& p, int q) : price(p), quantity(q) {}

    void printOrder() {
        cout << "Order: " << quantity << " items at " << price.currency << price.amount << "\n";
    }
};

// Case Statements in Object-Oriented Code: Refactored
class ShapeBase {
public:
    virtual void draw() const = 0;
};

class Circle : public ShapeBase {
public:
    void draw() const override { cout << "Drawing a Circle\n"; }
};

class Square : public ShapeBase {
public:
    void draw() const override { cout << "Drawing a Square\n"; }
};

class Triangle : public ShapeBase {
public:
    void draw() const override { cout << "Drawing a Triangle\n"; }
};

// Parallel Inheritance: Refactored
class Toy {
public:
    virtual void playSound() const = 0;
};

class AnimalBase {
protected:
    shared_ptr<Toy> toy;

public:
    AnimalBase(shared_ptr<Toy> t) : toy(t) {}
    virtual void makeSound() const = 0;
    void playToy() const { toy->playSound(); }
};

class DogBase : public AnimalBase {
public:
    DogBase(shared_ptr<Toy> t) : AnimalBase(t) {}
    void makeSound() const override { cout << "Bark!\n"; }
};

class DogToyBase : public Toy {
public:
    void playSound() const override { cout << "Squeak Bark!\n"; }
};

// Lazy Class: Refactored
class ProductOrderWithDiscount {
public:
    Money price;
    int quantity;

    ProductOrderWithDiscount(const Money& p, int q) : price(p), quantity(q) {}

    void applyDiscount() {
        if (price.amount * quantity > 100) cout << "Applying discount\n";
    }
};
