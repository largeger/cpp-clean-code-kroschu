#include <iostream>
#include <memory>
#include <string>

/*
Explanation
1. Tight Coupling (TightlyCoupledWeatherApp):
    - TightlyCoupledWeatherApp has a direct dependency on the APIService class.
    - Changing to another service, such as MockService, would require modifying TightlyCoupledWeatherApp to replace APIService with the new service.
2. Loose Coupling (LooselyCoupledWeatherApp):
    - The LooselyCoupledWeatherApp depends on an interface IWeatherService, not a concrete implementation.
    - APIService and MockService implement IWeatherService, allowing LooselyCoupledWeatherApp to use any service that conforms to this interface.
    - Switching from LooseAPIService to MockService requires no changes to LooselyCoupledWeatherApp.
*/

// Tight Coupling Example
class APIService {
public:
    std::string fetchWeatherData() const {
        return "Sunny, 25°C from API Service";
    }
};

class TightlyCoupledWeatherApp {
public:
    TightlyCoupledWeatherApp() : service() {}

    void displayWeather() const {
        std::cout << "Weather: " << service.fetchWeatherData() << std::endl;
    }

private:
    APIService service;  // Direct dependency on APIService
};

// Loose Coupling Example with Interface
class IWeatherService {
public:
    virtual ~IWeatherService() = default;
    virtual std::string fetchWeatherData() const = 0;
};

class LooseAPIService : public IWeatherService {
public:
    std::string fetchWeatherData() const override {
        return "Sunny, 25°C from Loose API Service";
    }
};

class MockService : public IWeatherService {
public:
    std::string fetchWeatherData() const override {
        return "Mock weather: Cloudy, 20°C";
    }
};

class LooselyCoupledWeatherApp {
public:
    LooselyCoupledWeatherApp(std::shared_ptr<IWeatherService> service) 
        : service(std::move(service)) {}

    void displayWeather() const {
        std::cout << "Weather: " << service->fetchWeatherData() << std::endl;
    }

private:
    std::shared_ptr<IWeatherService> service;  // Dependency on interface
};

int main() {
    std::cout << "Tight Coupling Example:" << std::endl;
    TightlyCoupledWeatherApp tightlyCoupledApp;
    tightlyCoupledApp.displayWeather();

    std::cout << "\nLoose Coupling Example:" << std::endl;
    auto apiService = std::make_shared<LooseAPIService>();
    LooselyCoupledWeatherApp looselyCoupledApp(apiService);
    looselyCoupledApp.displayWeather();

    // Switch to mock service without changing LooselyCoupledWeatherApp
    auto mockService = std::make_shared<MockService>();
    LooselyCoupledWeatherApp looselyCoupledAppWithMock(mockService);
    looselyCoupledAppWithMock.displayWeather();

    return 0;
}
