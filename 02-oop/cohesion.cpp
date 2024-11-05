#include <iostream>
#include <string>
#include <vector>
/*
Explanation
1. Low Cohesion (UserAccount):
    - The UserAccount class handles both user data management and display functions (printing user details and friends).
    - Mixing responsibilities makes the class harder to maintain, as any changes to data handling or printing would require modifying UserAccount.
2. High Cohesion (UserManager and UserPrinter):
    - UserManager is responsible only for managing user data, encapsulating details about the user's name, age, and friends.
    - UserPrinter is solely responsible for displaying the user information and friends list.
    - Each class has a single, focused responsibility, making them easy to maintain and extend individually.
*/

// Low Cohesion Example
class UserAccount {
public:
    UserAccount(const std::string& name, int age) : name(name), age(age) {}

    void addFriend(const std::string& friendName) {
        friends.push_back(friendName);
    }

    void displayUserDetails() const {
        std::cout << "User: " << name << ", Age: " << age << std::endl;
    }

    void printFriends() const {
        std::cout << "Friends of " << name << ":" << std::endl;
        for (const auto& friendName : friends) {
            std::cout << "- " << friendName << std::endl;
        }
    }

private:
    std::string name;
    int age;
    std::vector<std::string> friends;
};

// High Cohesion Example
class UserManager {
public:
    UserManager(const std::string& name, int age) : name(name), age(age) {}

    void addFriend(const std::string& friendName) {
        friends.push_back(friendName);
    }

    const std::string& getName() const { return name; }
    int getAge() const { return age; }
    const std::vector<std::string>& getFriends() const { return friends; }

private:
    std::string name;
    int age;
    std::vector<std::string> friends;
};

class UserPrinter {
public:
    static void displayUserDetails(const UserManager& user) {
        std::cout << "User: " << user.getName() << ", Age: " << user.getAge() << std::endl;
    }

    static void printFriends(const UserManager& user) {
        std::cout << "Friends of " << user.getName() << ":" << std::endl;
        for (const auto& friendName : user.getFriends()) {
            std::cout << "- " << friendName << std::endl;
        }
    }
};

int main() {
    // Low Cohesion example
    std::cout << "Low Cohesion Example:" << std::endl;
    UserAccount user1("Alice", 30);
    user1.addFriend("Bob");
    user1.addFriend("Charlie");
    user1.displayUserDetails();
    user1.printFriends();

    std::cout << "\nHigh Cohesion Example:" << std::endl;
    UserManager user2("Alice", 30);
    user2.addFriend("Bob");
    user2.addFriend("Charlie");

    UserPrinter::displayUserDetails(user2);
    UserPrinter::printFriends(user2);

    return 0;
}
