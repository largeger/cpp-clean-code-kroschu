#include <iostream>
#include <string>
/*
In this example:
- The Report class has three responsibilities: generating the report, formatting it, and printing it.
- This violates the Single Responsibility Principle because changes in any of these functionalities could require changes in this one class, creating a tightly coupled design.
*/
class Report {
private:
    std::string content;

public:
    Report(const std::string& text) : content(text) {}

    void generate() {
        content = "Report Content: " + content;
    }

    std::string formatReport() {
        return "Formatted Report: " + content;
    }

    void printReport() {
        std::cout << formatReport() << std::endl;
    }
};

int main() {
    Report report("Annual Financial Summary");
    report.generate();
    report.printReport();

    return 0;
}
