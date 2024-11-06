#include <iostream>

// Target Interface: Square
// This is the interface that clients expect, defining a getSideLength method.
class Square {
public:
    virtual float getSideLength() const = 0;
};

// Adaptee Class: Rectangle
// This is the incompatible class we want to adapt. It has getWidth and getHeight methods instead of getSideLength.
class Rectangle {
private:
    float width;
    float height;

public:
    Rectangle(float width, float height) : width(width), height(height) {}

    float getWidth() const {
        return width;
    }

    float getHeight() const {
        return height;
    }
};

// Adapter Class: RectangleToSquareAdapter
// This class adapts Rectangle to the Square interface. 
// It holds a reference to a Rectangle object and implements getSideLength. 
// If the Rectangle is actually square-like (width equals height), it returns the width as the side length; 
// otherwise, it prints a warning and returns 0.0f.
class RectangleToSquareAdapter : public Square {
private:
    Rectangle& rectangle;

public:
    RectangleToSquareAdapter(Rectangle& rect) : rectangle(rect) {}

    float getSideLength() const override {
        // Assume the rectangle is square-like if width equals height
        if (rectangle.getWidth() == rectangle.getHeight()) {
            return rectangle.getWidth();
        } else {
            std::cerr << "Warning: Rectangle is not a square!\n";
            return 0.0f; // Or throw an exception, depending on your requirements
        }
    }
};

// Client code
// In main(), we create a "square" rectangle and a non-square rectangle. We then use the RectangleToSquareAdapter to treat these rectangles as squares. The adapter checks if the rectangle is a square and outputs the side length accordingly.
int main() {
    Rectangle squareRect(10.0f, 10.0f); // A square-like rectangle
    Rectangle nonSquareRect(10.0f, 20.0f); // Not a square

    // Using the adapter to treat Rectangle as Square
    RectangleToSquareAdapter squareAdapter(squareRect);
    RectangleToSquareAdapter nonSquareAdapter(nonSquareRect);

    std::cout << "Square side length: " << squareAdapter.getSideLength() << "\n";
    std::cout << "Non-square side length: " << nonSquareAdapter.getSideLength() << "\n";

    return 0;
}
