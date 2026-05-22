#include <iomanip>
#include <iostream>
#include <string>
#include <format>

double deposit(double balance, double amount) {
    if (amount == 0) {
        std::cout << "Sorry, you cannot deposit $0.\n";

        return balance;
    }

    if (amount < 0) {
        std::cout << "Sorry, the amount you deposit cannot be negative.\n";

        return balance;
    }

    return balance + amount;
}

double withdraw(double balance, double amount) {
    if (amount < 0) {
        std::cout << "Sorry, the amount you withdraw cannot be negative.\n";

        return balance;
    }

    if (amount > balance) {
        std::cout << "Insufficient funds. Balance unchanged: $" << std::fixed << std::setprecision(2) << balance << '\n';

        return balance;
    }

    return balance - amount;
}

int main() {
    std::string transactionHistory { };

    std::string holderName { };
    double balance { };

    std::cout << "Enter account holder name: ";
    std::getline(std::cin, holderName);

    std::cout << "Enter opening balance: ";
    std::cin >> balance;

    std::cout << '\n';

    // opening balance was negative
    if (balance < 0) {
        std::cout << "Sorry, your opening balance cannot be negative.\n";
        return 0;
    }

    // account is premium vs standard
    if (balance > 1000) {
        std::cout << "[Premium Account]\n";
    } else {
        std::cout << "[Standard Account]\n";
    }

    std::cout << "Welcome, " << holderName << "!\n";
    std::cout << "Current balance: $" << std::fixed << std::setprecision(2) << balance << '\n';

    // menu loop
    while (true) {
        std::cout << '\n';
        std::cout << "--- Menu ---\n";
        std::cout << "1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. View Balance\n";
        std::cout << "4. Quit\n";

        int choice { };
        std::cout << "Choice: ";
        std::cin >> choice;

        if (choice == 1) {
            double amount { };
            std::cout << "Amount: ";
            std::cin >> amount;

            double newBalance { deposit(balance, amount) };

            if (newBalance != balance) {
                transactionHistory += ("Deposit $" + std::format("{:.2f}", amount) + "\n");

                std::cout << "Deposited $" << std::fixed << std::setprecision(2) << amount << ". New balance: $" << newBalance << '\n';
            }

            balance = newBalance;

        } else if (choice == 2) {
            double amount { };
            std::cout << "Amount: ";
            std::cin >> amount;

            double newBalance { withdraw(balance, amount) };

            if (newBalance != balance) {
                transactionHistory += ("Withdraw $" + std::format("{:.2f}", amount) + "\n");

                std::cout << "Withdrawn $" << std::fixed << std::setprecision(2) << amount << ". New balance: $" << newBalance << '\n';
            }

            balance = newBalance;
        } else if (choice == 3) {
            std::cout << "Transaction History: \n";
            std::cout << transactionHistory << '\n';

            std::cout << "Your account balance is: $" << std::fixed << std::setprecision(2) << balance << '\n';
        } else if(choice == 4) {
            std::cout << "Goodbye, " << holderName << "!\n";
            break;
        } else {
            std::cout << "Please input a number 1-4.\n";
        }
    }

    return 0;
}
