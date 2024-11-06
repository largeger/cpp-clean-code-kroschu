#include <iostream>
#include <memory>
#include <vector>
/*
In this example:

- We create an IWorker interface that Worker and Robot implement.
- The Manager class depends on the IWorker abstraction, not specific worker implementations.
- This adheres to DIP, allowing the Manager class to work with any class that implements IWorker, making the system more flexible and easier to extend.
*/
class IWorker {
public:
    virtual void work() = 0;
    virtual ~IWorker() = default;
};

class Worker : public IWorker {
public:
    void work() override {
        std::cout << "Worker is working..." << std::endl;
    }
};

class Robot : public IWorker {
public:
    void work() override {
        std::cout << "Robot is working..." << std::endl;
    }
};

class Manager {
private:
    std::vector<std::shared_ptr<IWorker>> workers;

public:
    void addWorker(const std::shared_ptr<IWorker>& worker) {
        workers.push_back(worker);
    }

    void manage() {
        for (const auto& worker : workers) {
            worker->work();
        }
    }
};

int main() {
    auto worker = std::make_shared<Worker>();
    auto robot = std::make_shared<Robot>();

    Manager manager;
    manager.addWorker(worker);
    manager.addWorker(robot);

    manager.manage();

    return 0;
}
