#include <iostream>
#include <string>
/*
Explanation:

- The Manager class directly depends on the Worker and Robot classes.
- This violates DIP because Manager depends on specific implementations, making it difficult to change or extend with new types of workers.
*/
class Worker {
public:
    void work() {
        std::cout << "Worker is working..." << std::endl;
    }
};

class Robot {
public:
    void work() {
        std::cout << "Robot is working..." << std::endl;
    }
};

class Manager {
private:
    Worker* worker;
    Robot* robot;

public:
    Manager(Worker* w, Robot* r) : worker(w), robot(r) {}

    void manage() {
        worker->work();
        robot->work();
    }
};

int main() {
    Worker worker;
    Robot robot;
    Manager manager(&worker, &robot);

    manager.manage();

    return 0;
}
