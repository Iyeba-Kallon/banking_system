#include <iostream>     // for input and output
#include <iomanip>      // for formatting decimal output
using namespace std;

// BankAccount class definition
class BankAccount {
private:
    double balance;  // private member to store the account balance

public:
    // Constructor to initialize account with an initial balance
    BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    // Method to deposit amount into account
    void deposit(double amount) {
        if (amount < 0) {
            cout << "Amount must be positive!" << endl;
            return;
        }
        balance += amount;  // add to balance
        cout << fixed << setprecision(2); // format to 2 decimal places
        cout << "Deposited: " << amount << endl;
    }

    // Method to withdraw amount from account
    void withdraw(double amount) {
        if (amount < 0) {
            cout << "Amount must be positive!" << endl;
            return;
        }
        if (amount > balance) {
            cout << "Insufficient Funds!" << endl;
        } else {
            balance -= amount; // subtract from balance
            cout << fixed << setprecision(2);
            cout << "Withdrawn: " << amount << endl;
        }
    }

    // Method to display current balance
    void checkBalance() {
        cout << fixed << setprecision(2);
        cout << "Current balance: " << balance << endl;
    }
};

// Main function - program starts here
int main() {
    double initialBalance;

    // Ask user for starting balance
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    // Create an account object with the given initial balance
    BankAccount account(initialBalance);

    // Infinite loop to keep showing menu until user exits
    while (true) {
        // Display menu options
        cout << "\n1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        // Handle user's choice
        switch (choice) {
            case 1: {
                double amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount); // call deposit method
                break;
            }
            case 2: {
                double amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount); // call withdraw method
                break;
            }
            case 3:
                account.checkBalance(); // call balance check method
                break;
            case 4:
                return 0; // exit program
            default:
                cout << "Invalid choice!" << endl; // catch invalid input
        }
    }
}
