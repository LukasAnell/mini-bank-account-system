#include <cstddef>
#include <iomanip>
#include <iostream>
#include <string>
#include <format>
#include <vector>

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
    std::vector<std::string> transactionHistories { };

    std::vector<std::string> names { };
    std::vector<double> balances { };

    int numAccounts { };
    std::cout << "How many accounts? ";
    std::cin >> numAccounts;

    for (int i { 1 }; i <= numAccounts; ++i) {
        std::cout << '\n';

        std::string name { };
        double balance { };

        std::cout << "Account " << i << " name: ";
        std::getline(std::cin >> std::ws, name);
        names.push_back(name);

        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Account " << i << " opening balance: ";
        std::cin >> balance;
        balances.push_back(balance);

        transactionHistories.push_back("");
    }

    std::cout << '\n';

    std::cout << "--- Accounts ---\n";
    for (size_t i { }; i < names.size(); ++i) {
        std::string name { names.at(i) };
        double balance { balances.at(i) };

        if (balance < 0) {
            std::cout <<"Your opening balance cannot be negative.\n";
            return 0;
        }

        std::string accountType { };
        if (balance > 1000) {
            accountType = "Premium";
        } else {
            accountType = "Standard";
        }

        std::cout << (i + 1)  << ". " << name << " $" << std::fixed << std::setprecision(2) << balance << " [" << accountType << "]\n";
    }

    std::cout << '\n';

    size_t selectedAccountIndex { 0 };
    std::string name = names.at(selectedAccountIndex);
    double balance = balances.at(selectedAccountIndex);

    bool menuLoop { true };

    // menu loop
    while (menuLoop) {
        std::cout << '\n';

        std::cout << "Active account: " << name << '\n';

        std::cout << "--- Menu ---\n";

        std::cout << "0. Switch Account\n";
        std::cout << "1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. View Balance\n";
        std::cout << "4. Quit\n";

        int choice { };
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 0: {
                int newIndex { };
                std::cout << "Select account (1-" << names.size() << "): ";
                std::cin >> newIndex;

                newIndex--;

                if (newIndex < 0 || static_cast<size_t>(newIndex) > names.size()) {
                    std::cout << "Please select a number between 1-" << names.size() << ".\n";

                    continue;
                }

                selectedAccountIndex = static_cast<size_t>(newIndex);

                name = names.at(selectedAccountIndex);
                balance = balances.at(selectedAccountIndex);

                std::cout << "Switched to " << name << ".\n";

                break;
            }
            case 1: {
                double amount { };
                std::cout << "Amount: ";
                std::cin >> amount;

                double newBalance { deposit(balance, amount) };

                if (newBalance != balance) {
                    transactionHistories.at(selectedAccountIndex) += ("Deposit $" + std::format("{:.2f}", amount) + "\n");

                    std::cout << "Deposited $" << std::fixed << std::setprecision(2) << amount << ". New balance: $" << newBalance << '\n';
                }

                balance = newBalance;

                break;
            }
            case 2: {
                double amount { };
                std::cout << "Amount: ";
                std::cin >> amount;

                double newBalance { withdraw(balance, amount) };

                if (newBalance != balance) {
                    transactionHistories.at(selectedAccountIndex) += ("Withdraw $" + std::format("{:.2f}", amount) + "\n");

                    std::cout << "Withdrawn $" << std::fixed << std::setprecision(2) << amount << ". New balance: $" << newBalance << '\n';
                }

                balance = newBalance;

                break;
            }
            case 3: {
                std::cout << "Transaction History: \n";

                if (transactionHistories.at(selectedAccountIndex).empty()) {
                    std::cout << "No transaction history recorded yet.\n";
                } else {
                    std::cout << transactionHistories.at(selectedAccountIndex) << '\n';
                }

                std::cout << "Your account balance is: $" << std::fixed << std::setprecision(2) << balance << '\n';

                break;
            }
            case 4: {
                std::cout << "--- Accounts ---\n";
                for (size_t i { }; i < names.size(); ++i) {
                    std::string n { names.at(i) };
                    double b { balances.at(i) };

                    if (b < 0) {
                        std::cout <<"Your opening balance cannot be negative.\n";
                        return 0;
                    }

                    std::string accountType { };
                    if (b > 1000) {
                        accountType = "Premium";
                    } else {
                        accountType = "Standard";
                    }

                    std::cout << (i + 1)  << ". " << n << " $" << std::fixed << std::setprecision(2) << b << " [" << accountType << "]\n";
                }

                std::cout << "Goodbye!\n";

                menuLoop = false;

                break;
            }
            default: {
                std::cout << "Please input a number 0-4.\n";

                break;
            }
        }

        if (!menuLoop) {
            break;
        }
    }

    return 0;
}
