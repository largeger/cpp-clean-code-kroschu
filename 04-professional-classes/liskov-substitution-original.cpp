#include <iostream>
/*
Explanation:
- Square overrides setWidth and setHeight to ensure both dimensions are the same, violating the expectation that setWidth and setHeight work independently.
- This breaks the Liskov Substitution Principle because Square doesn’t behave like a true Rectangle, leading to unexpected results in testArea().
*/
class Rectangle {
protected:
    int width;
    int height;

public:
    void setWidth(int w) {
        width = w;
    }

    void setHeight(int h) {
        height = h;
    }

    int getArea() const {
        return width * height;
    }
};

class Square : public Rectangle {
public:
    void setWidth(int w) {
        width = w;
        height = w; // Forces height to be the same as width
    }

    void setHeight(int h) {
        width = h;
        height = h; // Forces width to be the same as height
    }
};

void testArea(Rectangle& rect) {
    rect.setWidth(5);
    rect.setHeight(10);
    std::cout << "Expected area: 50, Actual area: " << rect.getArea() << std::endl;
}

int main() {
    Rectangle rect;
    testArea(rect); // expected behaviour: 50

    Square square;
    testArea(square); // unexpected behavior: 50

    return 0;
}
