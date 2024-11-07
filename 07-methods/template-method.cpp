#include <iostream>
#include <cmath>

/*
Explanation
- PointCreator (Abstract Class): This class defines the template method createPoint, which uses computeX and computeY to calculate the x and y coordinates. These methods are marked as virtual and = 0, making PointCreator an abstract class.
- CartesianPointCreator: Implements computeX and computeY for Cartesian coordinates. In Cartesian coordinates, a and b correspond directly to x and y.
- PolarPointCreator: Implements computeX and computeY for Polar coordinates. Here, a is treated as the radius and b as the angle in radians.
- Usage in main(): We instantiate the concrete creators, CartesianPointCreator and PolarPointCreator, and use them to create Point objects with different coordinate systems. Each creator follows the template method pattern to produce Point objects.
*/
class Point {
private:
    float x, y;

public:
    Point(float x, float y) : x(x), y(y) {}

    void display() const {
        std::cout << "Point(" << x << ", " << y << ")\n";
    }
};

// Abstract class defining the Template Method pattern
class PointCreator {
public:
    // The Template Method defining the skeleton for creating a Point
    Point createPoint(float a, float b) {
        float x = computeX(a, b);
        float y = computeY(a, b);
        return Point(x, y);
    }

protected:
    // Steps to be implemented by subclasses
    virtual float computeX(float a, float b) const = 0;
    virtual float computeY(float a, float b) const = 0;
};

// Concrete subclass for creating Cartesian points
class CartesianPointCreator : public PointCreator {
protected:
    float computeX(float a, float /* b */) const override {
        return a;
    }

    float computeY(float /* a */, float b) const override {
        return b;
    }
};

// Concrete subclass for creating Polar points
class PolarPointCreator : public PointCreator {
protected:
    float computeX(float radius, float angleInRadians) const override {
        return radius * cos(angleInRadians);
    }

    float computeY(float radius, float angleInRadians) const override {
        return radius * sin(angleInRadians);
    }
};

// Usage example
int main() {
    // Using CartesianPointCreator to create a Point in Cartesian coordinates
    PointCreator* cartesianCreator = new CartesianPointCreator();
    Point cartesianPoint = cartesianCreator->createPoint(10, 20);
    cartesianPoint.display();

    // Using PolarPointCreator to create a Point in Polar coordinates
    PointCreator* polarCreator = new PolarPointCreator();
    Point polarPoint = polarCreator->createPoint(10.0f, 20.0f);
    polarPoint.display();

    delete cartesianCreator;
    delete polarCreator;

    return 0;
}
