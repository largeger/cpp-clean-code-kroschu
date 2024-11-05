#include <iostream>
#include <string>

/*
Explanation
Encapsulation through Access Modifiers:

The owner and balance variables are private, hiding them from external access. Only methods within the BankAccount class can directly interact with these variables.
Public Interface:

The methods deposit(), withdraw(), getBalance(), and getOwner() provide controlled access to the private data.
This ensures that balance adjustments are made only through deposit() and withdraw() with specific checks (e.g., amount > 0, amount <= balance).
Encapsulation Benefits:

The account's balance and owner data are protected from outside interference, and the class enforces rules for valid transactions.
*/
class BankAccount {
public:
    // Constructor to initialize account with owner's name and initial balance
    BankAccount(const std::string& owner, double initialBalance) 
        : owner(owner), balance(initialBalance) {}

    // Public method to deposit money (positive value only)
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << std::endl;
        } else {
            std::cout << "Invalid deposit amount!" << std::endl;
        }
    }

    // Public method to withdraw money (ensures sufficient balance)
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrew: $" << amount << std::endl;
        } else {
            std::cout << "Invalid withdrawal amount or insufficient funds!" << std::endl;
        }
    }

    // Public method to check balance (read-only access)
    double getBalance() const {
        return balance;
    }

    // Public method to get the account owner's name
    std::string getOwner() const {
        return owner;
    }

private:
    std::string owner;  // Private member variable to store the owner's name
    double balance;     // Private member variable to store the account balance
};

int main() {
    BankAccount account("Alice", 500.0);  // Create account with initial balance of $500

    std::cout << "Account owner: " << account.getOwner() << std::endl;
    std::cout << "Initial balance: $" << account.getBalance() << std::endl;

    account.deposit(200.0);   // Deposit $200
    std::cout << "New balance: $" << account.getBalance() << std::endl;

    account.withdraw(150.0);  // Withdraw $150
    std::cout << "New balance: $" << account.getBalance() << std::endl;

    account.withdraw(700.0);  // Attempt to withdraw more than the balance
    std::cout << "Final balance: $" << account.getBalance() << std::endl;

    return 0;
}