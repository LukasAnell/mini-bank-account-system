#include <iomanip>
#include <iostream>

int main() {
    std::string holderName { };
    double openingBalance { };

    std::cout << "Enter account holder name: ";
    std::getline(std::cin, holderName);

    std::cout << "Enter opening balance: ";
    std::cin >> openingBalance;

    std::cout << '\n';

    // opening balance was negative
    if (openingBalance < 0) {
        std::cout << "Sorry, your opening balance cannot be negative.\n";
        return 0;
    }

    // account is premium vs standard
    if (openingBalance > 1000) {
        std::cout << "[Premium Account]\n";
    } else {
        std::cout << "[Standard Account]\n";
    }

    std::cout << "Welcome, " << holderName << "!\n";
    std::cout << "Current balance: $" << std::fixed << std::setprecision(2) << openingBalance << '\n';

    std::cout << '\n';

    std::string response { };
    std::cout << "Is your balance above $1000? (y/n): ";
    std::cin >> response;

    // right or wrong
    if (response == "y") {
        if (openingBalance > 1000) {
            std::cout << "Correct! Your balance is above $1000.\n";
        } else {
            std::cout << "Wrong! Your balance is not above $1000.\n";
        }
    } else {
        if (openingBalance > 1000) {
            std::cout << "Wrong! Your balance is above $1000.\n";
        } else {
            std::cout << "Correct! Your balance is not above $1000.\n";
        }
    }

    return 0;
}
