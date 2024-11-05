#include <iostream>
#include <memory>
#include <string>

/*
Explanation
Composition:

Car contains an Engine object using std::unique_ptr<Engine>. The Engine is created when the Car is constructed, and it can't exist outside of it.

Aggregation:

Car has a Driver object through std::shared_ptr<Driver>. This allows the Driver to exist independently and be shared with other instances of Car.
*/

class Engine {
public:
    Engine(const std::string& model) : model(model) {}
    void start() const { std::cout << "Engine " << model << " started." << std::endl; }
    std::string getModel() const { return model; }

private:
    std::string model;
};

class Driver {
public:
    Driver(const std::string& name) : name(name) {}
    void drive() const { std::cout << "Driver " << name << " is driving." << std::endl; }
    std::string getName() const { return name; }

private:
    std::string name;
};

class Car {
public:
    Car(const std::string& brand, const std::string& engineModel) 
        : brand(brand), engine(std::make_unique<Engine>(engineModel)) {}

    void setDriver(const std::shared_ptr<Driver>& driver) { this->driver = driver; }
    void start() const {
        std::cout << "Car " << brand << " is starting." << std::endl;
        engine->start();
        if (driver) driver->drive();
        else std::cout << "No driver assigned." << std::endl;
    }

private:
    std::string brand;
    std::unique_ptr<Engine> engine;       // Composition: Car *owns* the engine
    std::shared_ptr<Driver> driver;       // Aggregation: Car *uses* the driver
};

int main() {
    // Composition: Car contains an Engine
    Car myCar("Toyota", "V8");

    // Aggregation: Driver is shared and can be assigned to different cars
    std::shared_ptr<Driver> driver = std::make_shared<Driver>("Alice");
    myCar.setDriver(driver);

    myCar.start();   // Start the car with the assigned driver

    return 0;
}
