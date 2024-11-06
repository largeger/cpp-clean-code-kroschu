#include <iostream>
#include <vector>
#include <memory>
/*
In this example:
- Each shape class (Rectangle, Circle) implements a getArea method from the Shape interface.
- AreaCalculator uses polymorphism to calculate the total area without needing to know the specifics of each shape.
- This design adheres to the Open/Closed Principle since new shapes can be added by extending Shape without modifying AreaCalculator.
*/
class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const override {
        return 3.14159 * radius * radius;
    }
};

class AreaCalculator {
public:
    double calculateTotalArea(const std::vector<std::shared_ptr<Shape>>& shapes) const {
        double totalArea = 0.0;
        for (const auto& shape : shapes) {
            totalArea += shape->getArea();
        }
        return totalArea;
    }
};

int main() {
    auto rect = std::make_shared<Rectangle>(5, 10);
    auto circ = std::make_shared<Circle>(7);

    std::vector<std::shared_ptr<Shape>> shapes = { rect, circ };

    AreaCalculator calculator;
    std::cout << "Total Area: " << calculator.calculateTotalArea(shapes) << std::endl;

    return 0;
}
