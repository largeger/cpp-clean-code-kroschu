#include <iostream>
#include <vector>
#include <string>
#include <ctime>

class Manage
{
public:
    int age;
    std::string nam; // This variable represents the name

    Manage() {
        age = 0;
        nam = "Unnamed";
    }

    void set_values(int a, std::string n) {
        age = a;
        nam = n;
    }

    void print() {
        std::cout << "Name: " << nam << ", Age: " << age << std::endl;
    }
};

class Control
{
public:
    static void print_time() { 
        std::time_t t = std::time(nullptr);
        std::cout << "Time: " << std::asctime(std::localtime(&t));
    }

    void printStatus() { 
        // Print the status
        std::cout << "Status: Active\n";
    }
};

class Worker 
{
    int m_value;
    std::vector<int> m_data; 
public:
    Worker(int value = 0) {
        m_value = value;
    }

    void add_value(int val) { 
        m_value += val; // Increment m_value by the input
        m_data.push_back(val); // Adds value to the data list
    }

    void print_data() { 
        std::cout << "Values: ";
        for (auto v : m_data) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
};

class DoWork 
{
public:
    void performTask(Worker* worker) { 
        for (int i = 0; i < 5; i++) {
            worker->add_value(i); // Adds incremental values to worker
        }
    }
};

int main() {
    Manage manager;
    manager.set_values(25, "Alice");
    manager.print();

    Control::print_time(); 
    Control control;
    control.printStatus();

    Worker work;
    DoWork taskDoer;
    taskDoer.performTask(&work);
    work.print_data();

    return 0;
}
