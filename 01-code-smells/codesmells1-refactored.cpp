#include <iostream>
#include <string>

using namespace std;

// Long Function: Refactored
void validateOrder() {
    cout << "Validating order...\n";
}

void applyDiscount() {
    cout << "Applying discount...\n";
}

double calculateTax() {
    cout << "Calculating tax...\n";
    return 0.1; // Dummy tax
}

void processPayment() {
    cout << "Processing payment...\n";
}

void sendConfirmationEmail() {
    cout << "Sending confirmation email...\n";
}

void processOrderRefactored() {
    validateOrder();
    applyDiscount();
    double tax = calculateTax();
    processPayment();
    sendConfirmationEmail();
}

// Duplicate Code: Refactored
double calculateArea(double width, double height = 0) {
    return height == 0 ? width * width : width * height;
}

// Magic Number: Refactored
const double SALES_TAX_RATE = 0.08;

double calculateFinalPriceRefactored(double price) {
    return price * SALES_TAX_RATE;
}

// God Object: Refactored
class OrderValidator {
public:
    void validate() {
        cout << "Validating order...\n";
    }
};

class DiscountManager {
public:
    void apply() {
        cout << "Applying discount...\n";
    }
};

class TaxCalculator {
public:
    double calculate() {
        cout << "Calculating tax...\n";
        return 0.1; // Dummy tax
    }
};

class PaymentProcessor {
public:
    void process() {
        cout << "Processing payment...\n";
    }
};

// Excessive Comments: Refactored with Descriptive Names
bool isUserAuthenticated() {
    return true;
}

void showUserProfile() {
    cout << "Displaying user profile...\n";
}

// Shotgun Surgery: Refactored
class Logger {
public:
    void log(const string& message) {
        cout << "[LOG] " << message << "\n";
    }
};

void logOrder(Logger& logger) {
    logger.log("Order processed");
}

void logPayment(Logger& logger) {
    logger.log("Payment processed");
}

// Feature Envy: Refactored
class OrderRefactored {
    double price;
    int itemCount;
public:
    OrderRefactored(double p, int count) : price(p), itemCount(count) {}
    double calculateShippingCost() const {
        if (itemCount > 5) return 0;
        if (price > 100) return 5;
        return 10;
    }
};

int main() {
    cout << "=== Long Function ===\n";
    processOrderRefactored();

    cout << "\n=== Duplicate Code ===\n";
    cout << "Area (Refactored): " << calculateArea(5, 10) << "\n";

    cout << "\n=== Magic Number ===\n";
    cout << "Final Price (Refactored): " << calculateFinalPriceRefactored(100) << "\n";

    cout << "\n=== God Object ===\n";
    OrderValidator validator;
    DiscountManager discountManager;
    TaxCalculator taxCalculator;
    PaymentProcessor paymentProcessor;
    validator.validate();
    discountManager.apply();
    taxCalculator.calculate();
    paymentProcessor.process();

    cout << "\n=== Excessive Comments ===\n";
    if (isUserAuthenticated()) showUserProfile();

    cout << "\n=== Shotgun Surgery ===\n";
    Logger logger;
    logOrder(logger);
    logPayment(logger);

    cout << "\n=== Feature Envy ===\n";
    OrderRefactored refactoredOrder(150, 3);
    cout << "Shipping Cost (Refactored): " << refactoredOrder.calculateShippingCost() << "\n";

    return 0;
}
