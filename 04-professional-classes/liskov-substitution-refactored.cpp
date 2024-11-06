#include <iostream>
/*
In this example:

- We created a Shape base interface with getArea as a pure virtual method.
- Rectangle and Square each have independent implementations of getArea.
- This design allows both Rectangle and Square to be used interchangeably in testArea without any unexpected behavior, preserving the Liskov Substitution Principle.*/
class Shape {
public:
    virtual int getArea() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
protected:
    int width;
    int height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    void setWidth(int w) {
        width = w;
    }

    void setHeight(int h) {
        height = h;
    }

    int getArea() const override {
        return width * height;
    }
};

class Square : public Shape {
private:
    int side;

public:
    Square(int s) : side(s) {}

    void setSide(int s) {
        side = s;
    }

    int getArea() const override {
        return side * side;
    }
};

void testArea(Shape& shape) {
    std::cout << "Area: " << shape.getArea() << std::endl;
}

int main() {
    Rectangle rect(5, 10);
    testArea(rect);

    Square square(5);
    testArea(square);

    return 0;
}
