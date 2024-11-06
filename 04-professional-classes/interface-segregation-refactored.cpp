#include <iostream>
#include <string>
/*
In this example:

- We split the interfaces into Workable, Eatable, and Sleepable.
- HumanWorker implements all three interfaces, while RobotWorker implements only Workable.
- Each class now only depends on the methods it needs, adhering to the Interface Segregation Principle and resulting in a cleaner design.*/
class Workable {
public:
    virtual void work() = 0;
    virtual ~Workable() = default;
};

class Eatable {
public:
    virtual void eat() = 0;
    virtual ~Eatable() = default;
};

class Sleepable {
public:
    virtual void sleep() = 0;
    virtual ~Sleepable() = default;
};

class HumanWorker : public Workable, public Eatable, public Sleepable {
public:
    void work() override {
        std::cout << "Human is working..." << std::endl;
    }

    void eat() override {
        std::cout << "Human is eating..." << std::endl;
    }

    void sleep() override {
        std::cout << "Human is sleeping..." << std::endl;
    }
};

class RobotWorker : public Workable {
public:
    void work() override {
        std::cout << "Robot is working..." << std::endl;
    }
    // RobotWorker doesn’t need to implement `eat` and `sleep` interfaces.
};

int main() {
    HumanWorker human;
    RobotWorker robot;

    human.work();
    human.eat();
    human.sleep();

    robot.work();

    return 0;
}
