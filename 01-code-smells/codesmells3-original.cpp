#include <iostream>
#include <string>

// Temporary Fields Original
void temporaryFieldsExample() {
    class Order {
        int discount;
        int discountDays;
    public:
        Order() : discount(0), discountDays(0) {}

        void applyDiscount(int days) {
            discountDays = days;
            if (discountDays > 5) {
                discount = 10;
            }
            std::cout << "Temporary Fields - Discount applied: " << discount << "%" << std::endl;
        }
    };

    Order order;
    order.applyDiscount(6);
}

// Message Chain Original
void messageChainExample() {
    class Address {
    public:
        std::string getZipCode() const {
            return "12345";
        }
    };

    class Customer {
        Address address;
    public:
        Address getAddress() const {
            return address;
        }
    };

    class Order {
        Customer customer;
    public:
        void printCustomerZipCode() const {
            std::cout << "Message Chain - Zip Code: " << customer.getAddress().getZipCode() << std::endl;
        }
    };

    Order order;
    order.printCustomerZipCode();
}

// Middle Man Original
void middleManExample() {
    class Engine {
    public:
        void start() const {
            std::cout << "Middle Man - Engine starting..." << std::endl;
        }
    };

    class Car {
        Engine engine;
    public:
        void startEngine() const {
            engine.start();
        }
    };

    Car car;
    car.startEngine();
}

// Unnecessary Intimacy Original
void unnecessaryIntimacyExample() {
    class Password {
        std::string secret;
    public:
        Password(const std::string& s) : secret(s) {}
        std::string getSecret() const {
            return secret;
        }
    };

    class Authenticator {
    public:
        bool authenticate(const Password& password) const {
            return password.getSecret() == "admin";
        }
    };

    Password password("admin");
    Authenticator auth;
    std::cout << "Unnecessary Intimacy - Authentication: " << (auth.authenticate(password) ? "Success" : "Failure") << std::endl;
}

// Alternative Classes with Different Interfaces - Original
void alternativeClassesExample() {
    class JsonParser {
    public:
        void parseJson(const std::string& data) {
            std::cout << "Alternative Classes - Parsing JSON: " << data << std::endl;
        }
    };

    class XmlParser {
    public:
        void parseXml(const std::string& data) {
            std::cout << "Alternative Classes - Parsing XML: " << data << std::endl;
        }
    };

    JsonParser jsonParser;
    XmlParser xmlParser;
    jsonParser.parseJson("{ \"key\": \"value\" }");
    xmlParser.parseXml("<key>value</key>");
}

// Incomplete Library Class Original
void incompleteLibraryClassExample() {
    class LegacyLibrary {
    public:
        void doLegacyWork() {
            std::cout << "Incomplete Library Class - Legacy work done" << std::endl;
        }
    };

    LegacyLibrary legacy;
    legacy.doLegacyWork();
}

int main() {
    temporaryFieldsExample();
    messageChainExample();
    middleManExample();
    unnecessaryIntimacyExample();
    alternativeClassesExample();
    incompleteLibraryClassExample();
    return 0;
}
