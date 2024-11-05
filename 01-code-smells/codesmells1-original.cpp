#include <iostream>
#include <string>

using namespace std;

// Long Function: Original
void processOrderLong() {
    cout << "Processing order...\n";
    cout << "Validating order...\n";
    cout << "Applying discount...\n";
    cout << "Calculating tax...\n";
    cout << "Processing payment...\n";
    cout << "Sending confirmation email...\n";
}

// Duplicate Code: Original
double calculateRectangleArea(double width, double height) {
    return width * height;
}

double calculateSquareArea(double side) {
    return side * side;
}

// Magic Number: Original
double calculateFinalPriceMagic(double price) {
    return price * 0.08; // 0.08 is a magic number
}

// God Object: Original
class GodOrderProcessor {
public:
    void processOrder() {
        cout << "Processing order (God Object)...\n";
            // validate order
            // apply discount
            // calculate tax
            // process payment
            // send confirmation
    }
};

// Excessive Comments: Original
/*
    This function checks if a user is authenticated.

    Parameters:
    None

    Returns: true if the user is authenticated, false otherwise
*/
bool check() {
    return true;
}

// Dead Code: Original
void processOrderWithDeadCode() {
    // double oldTax = 0.05; // Old tax calculation, no longer used -> remove!
    double newTax = 0.1; // New tax calculation
    cout << "Processing order with tax: " << newTax << "\n";
}

// Shotgun Surgery: Original
/*
Smell: A small change requires modifying many different parts of the code.
Explanation: Shotgun Surgery occurs when a single responsibility is scattered across multiple classes or methods. When you need to make a small change (e.g., adding a new feature or fixing a bug), you have to make modifications in many different places. This is a sign of poor cohesion and makes the system more prone to errors, as missing one of the changes can lead to bugs.
*/
void logOrderProcessed() {
    cout << "Order processed\n";
}

void logPaymentProcessed() {
    cout << "Payment processed\n";
}

// Feature Envy: Original
/*
Smell: A method in one class is more interested in the data or functionality of another class than its own.
Explanation: Feature Envy occurs when a method accesses more data from another class than from its own class, indicating that it may be better placed in the class it "envies." This smell violates the principle of encapsulation because the method doesn't make effective use of its own class's data or functionality.
*/
class Order {
    double price;
    int itemCount;
public:
    Order(double p, int count) : price(p), itemCount(count) {}
    double getPrice() const { return price; }
    int getItemCount() const { return itemCount; }
};

class OrderProcessorFeatureEnvy {
public:
    double calculateShippingCost(const Order& order) {
        if (order.getItemCount() > 5) return 0;
        if (order.getPrice() > 100) return 5;
        return 10;
    }
};




int main() {
    cout << "=== Long Function ===\n";
    processOrderLong();

    cout << "\n=== Duplicate Code ===\n";
    cout << "Rectangle Area: " << calculateRectangleArea(5, 10) << "\n";
    cout << "Square Area: " << calculateSquareArea(5) << "\n";

    cout << "\n=== Magic Number ===\n";
    cout << "Final Price (Magic): " << calculateFinalPriceMagic(100) << "\n";

    cout << "\n=== God Object ===\n";
    GodOrderProcessor godProcessor;
    godProcessor.processOrder();

    cout << "\n=== Dead Code ===\n";
    processOrderWithDeadCode();

    cout << "\n=== Shotgun Surgery ===\n";
    logOrderProcessed();
    logPaymentProcessed();

    cout << "\n=== Feature Envy ===\n";
    Order order(150, 3);
    OrderProcessorFeatureEnvy processor;
    cout << "Shipping Cost (Feature Envy): " << processor.calculateShippingCost(order) << "\n";

    return 0;
}
