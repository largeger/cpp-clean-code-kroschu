#include <iostream>
#include <string>

// Temporary Fields Refactored
void temporaryFieldsRefactored() {
    class Order {
    public:
        void applyDiscount(int days) {
            int discount = (days > 5) ? 10 : 0;
            std::cout << "Temporary Fields Refactored - Discount applied: " << discount << "%" << std::endl;
        }
    };

    Order order;
    order.applyDiscount(6);
}

// Message Chain Refactored
void messageChainRefactored() {
    class Address {
    public:
        std::string getZipCode() const {
            return "12345";
        }
    };

    class Customer {
        Address address;
    public:
        std::string getCustomerZipCode() const {
            return address.getZipCode();
        }
    };

    class Order {
        Customer customer;
    public:
        void printCustomerZipCode() const {
            std::cout << "Message Chain Refactored - Zip Code: " << customer.getCustomerZipCode() << std::endl;
        }
    };

    Order order;
    order.printCustomerZipCode();
}

// Middle Man Refactored
void middleManRefactored() {
    class Engine {
    public:
        void start() const {
            std::cout << "Middle Man Refactored - Engine starting..." << std::endl;
        }
    };

    class Car {
    public:
        Engine engine;
    };

    Car car;
    car.engine.start();
}

// Unnecessary Intimacy Refactored
void unnecessaryIntimacyRefactored() {
    class Password {
        std::string secret;
    public:
        Password(const std::string& s) : secret(s) {}
        bool isValid(const std::string& input) const {
            return secret == input;
        }
    };

    class Authenticator {
    public:
        bool authenticate(const Password& password) const {
            return password.isValid("admin");
        }
    };

    Password password("admin");
    Authenticator auth;
    std::cout << "Unnecessary Intimacy Refactored - Authentication: " << (auth.authenticate(password) ? "Success" : "Failure") << std::endl;
}

// Alternative Classes with Different Interfaces Refactored
void alternativeClassesRefactored() {
    class DataParser {
    public:
        virtual void parse(const std::string& data) = 0;
        virtual ~DataParser() = default;
    };

    class JsonParser : public DataParser {
    public:
        void parse(const std::string& data) override {
            std::cout << "Alternative Classes Refactored - Parsing JSON: " << data << std::endl;
        }
    };

    class XmlParser : public DataParser {
    public:
        void parse(const std::string& data) override {
            std::cout << "Alternative Classes Refactored - Parsing XML: " << data << std::endl;
        }
    };

    JsonParser jsonParser;
    XmlParser xmlParser;
    jsonParser.parse("{ \"key\": \"value\" }");
    xmlParser.parse("<key>value</key>");
}

// Incomplete Library Class Refactored
void incompleteLibraryClassRefactored() {
    class LegacyLibrary {
    public:
        void doLegacyWork() {
            std::cout << "Incomplete Library Class Refactored - Legacy work done" << std::endl;
        }
    };

    class ModernLibraryAdapter {
        LegacyLibrary legacy;
    public:
        void doModernWork() {
            legacy.doLegacyWork();
        }
    };

    ModernLibraryAdapter modernAdapter;
    modernAdapter.doModernWork();
}

int main() {
    temporaryFieldsRefactored();
    messageChainRefactored();
    middleManRefactored();
    unnecessaryIntimacyRefactored();
    alternativeClassesRefactored();
    incompleteLibraryClassRefactored();
    return 0;
}
