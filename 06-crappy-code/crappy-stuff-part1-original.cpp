#include <iostream>
#include <vector>
#include <string>
#include <ctime>

// bad choice for class name, use a more descriptive name
class Manage
{
public:
    // encapsulating age?
    int age;
    // bad choice for a name, remove the unnecessary comment 
    std::string nam; // This variable represents the name

    Manage() {
        age = 0;
        nam = "Unnamed";
    }

    //parameter names are better described as age and name
    void set_values(int a, std::string n) { // camel-case - not following naming convention, setter for two values is not the general intention
        age = a;
        nam = n;
    }

    void print() {
        std::cout << "Name: " << nam << ", Age: " << age << std::endl;
    }
};

// 1. inconsistet method names
// 2. Control is a bad choice for a name
// 3. Single Responsibility Principle is hurt...
// 3.1 clarify this class' purpose
class Control
{
public:
    static void print_time() { // Why is this mehtod static? 
        std::time_t t = std::time(nullptr);
        std::cout << "Time: " << std::asctime(std::localtime(&t));
    }

    void printStatus() { 
        // remove comment: // Print the status
        std::cout << "Status: Active\n";
    }
};

class Worker 
{
    // is m_ the convention for member variables
    // m_value does not have to be a member variable
    int m_value;
    std::vector<int> m_data; // choose more descriptive names
public:
    Worker(int value = 0) {
        m_value = value;
    }

    /*
    1. choose a meaningful name
    2. this method has two different jobs -> separate that!
    3. remove the comments!
    */
    void add_value(int val) { 
        m_value += val; // Increment m_value by the input
        m_data.push_back(val); // Adds value to the data list
    }

    // name not following code conventions
    void print_data() { 
        std::cout << "Values: ";
        for (auto v : m_data) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
};

// unnecessary class, performTask should be moved to class Worker

class DoWork 
{
public:
    void performTask(Worker* worker) { // 1. The connection to worker violates the Dependency Inversion Principle!
                                       // 2. bad naming - again...
        for (int i = 0; i < 5; i++) {
            worker->add_value(i); // unnecessary comment :  // Adds incremental values to worker
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

    Worker work; // bad naming: worker would be at least a bit bett
    DoWork taskDoer; // non-speaking name
    taskDoer.performTask(&work);
    work.print_data();

    return 0;
}
