
#include <iostream>
#include <vector>
#include <string>
/*
In this example:

- AreaCalculator has to know about every shape type, checking the type string to calculate the area.
- This design violates the Open/Closed Principle because adding new shapes (e.g., Triangle) would require modifying calculateArea, leading to less maintainable code.
*/
class Rectangle {
public:
    double width;
    double height;

    Rectangle(double w, double h) : width(w), height(h) {}
};

class Circle {
public:
    double radius;

    Circle(double r) : radius(r) {}
};

class AreaCalculator {
public:
    double calculateArea(const std::vector<void*>& shapes, const std::string& type) {
        double area = 0.0;
        for (const auto& shape : shapes) {
            if (type == "rectangle") {
                Rectangle* rect = static_cast<Rectangle*>(shape);
                area += rect->width * rect->height;
            } else if (type == "circle") {
                Circle* circ = static_cast<Circle*>(shape);
                area += 3.14159 * circ->radius * circ->radius;
            }
            // New shape types require modifying this method
        }
        return area;
    }
};

int main() {
    Rectangle rect(5, 10);
    Circle circ(7);

    std::vector<void*> shapes = { &rect, &circ };

    AreaCalculator calculator;
    std::cout << "Total Area: " << calculator.calculateArea(shapes, "rectangle") + 
                 calculator.calculateArea(shapes, "circle") << std::endl;

    return 0;
}
