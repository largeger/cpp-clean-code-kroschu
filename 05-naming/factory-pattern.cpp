#include <iostream>
#include <cmath>
/*
Explanation
- Static Factory Methods: The Point class has two static methods:
    - FromCartesian to create a point using Cartesian (x, y) coordinates.
    - FromPolar to create a point using polar coordinates, where radius is the distance from the origin and angleInRadians is the angle from the positive x-axis.
- Private Constructor: The constructor for Point is private, enforcing the use of the factory methods to create instances.
- Usage: In main(), we demonstrate the creation of Point objects using both Cartesian and Polar coordinates, similar to the provided example syntax.
*/
class Point {
private:
    float x, y;

    // Private constructor to force the use of factory methods
    Point(float x, float y) : x(x), y(y) {}

public:
    // Factory method for Cartesian coordinates
    static Point FromCartesian(float x, float y) {
        return Point(x, y);
    }

    // Factory method for Polar coordinates
    static Point FromPolar(float radius, float angleInRadians) {
        return Point(radius * cos(angleInRadians), radius * sin(angleInRadians));
    }

    void display() const {
        std::cout << "Point(" << x << ", " << y << ")\n";
    }
};

// Usage example
int main() {
    // Create a Point using Cartesian coordinates
    Point upperLeft = Point::FromCartesian(10, 20);
    upperLeft.display();

    // Create a Point using Polar coordinates
    Point lowerRight = Point::FromPolar(10.0f, 20.0f);
    lowerRight.display();

    return 0;
}
