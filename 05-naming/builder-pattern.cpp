// PointBuilderWithFluentAPI.cpp
#include <iostream>
#include <cmath>

class Point {
private:
    float x, y;

    // Private constructor used by the builder
    Point(float x, float y) : x(x), y(y) {}

public:
    void display() const {
        std::cout << "Point(" << x << ", " << y << ")\n";
    }

    // PointBuilder class for fluent API
    class PointBuilder {
    private:
        float angle = 0.0f;
        float distance = 0.0f;

    public:
        PointBuilder& angleOf(float angleInRadians) {
            angle = angleInRadians;
            return *this;
        }

        PointBuilder& distanceOf(float distanceValue) {
            distance = distanceValue;
            return *this;
        }

        // Builds the Point object and returns it
        Point andReturnIt() const {
            return Point(distance * cos(angle), distance * sin(angle));
        }
    };

    // Static method to initiate the builder
    static PointBuilder buildWith() {
        return PointBuilder();
    }
};

// Usage example
int main() {
    // Create a Point using the builder with fluent API
    Point lowerRight = Point::buildWith()
                           .angleOf(10.0f)
                           .distanceOf(20.0f)
                           .andReturnIt();

    lowerRight.display();

    return 0;
}
