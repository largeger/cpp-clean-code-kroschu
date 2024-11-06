#include <iostream>
#include <string>
/*
In this example:

- The Worker interface has methods work, eat, and sleep, which don’t all apply to both HumanWorker and RobotWorker.
- RobotWorker is forced to implement eat and sleep even though they’re irrelevant, violating the Interface Segregation Principle by making RobotWorker dependent on methods it doesn’t use.*/
class Worker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
    virtual void sleep() = 0;
    virtual ~Worker() = default;
};

class HumanWorker : public Worker {
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

class RobotWorker : public Worker {
public:
    void work() override {
        std::cout << "Robot is working..." << std::endl;
    }

    void eat() override {
        // Robot doesn't eat, but must implement this method.
    }

    void sleep() override {
        // Robot doesn't sleep, but must implement this method.
    }
};

int main() {
    HumanWorker human;
    RobotWorker robot;

    human.work();
    human.eat();
    human.sleep();

    robot.work();
    // eat() and sleep() methods are implemented but unnecessary for RobotWorker.

    return 0;
}
