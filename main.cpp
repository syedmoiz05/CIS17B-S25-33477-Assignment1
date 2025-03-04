#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <limits>

using namespace std;



// class for the bank account 
class bankaccount {
    private:
    string accountHolderName;
    int accountNumber;
    double balance;
    public:

    // constrcutor to initialize the account
    bankaccount(string name, double initialBalance) {
        accountHolderName = name;
        accountNumber = rand() % 1000000 + 1; // generates unique account number 
        balance = initialBalance;
    }

    // Function to deposit money, checks for validity and outputs new balance
void deposit(double amount) {
    if (amount > 0) {
        balance += amount; 
        cout << "Amount deposited: " << amount << ". New balance: " << balance << endl << endl;
    }
     else {
        cout << "Invalid amount, please select a new amount\n";
    }
}
// Function to withdraw money, checks for validity and outputs new balance
void withdraw(double amount) {
    if (amount <= 0) {
        cout << "Invalid amount, please enter a positive amount.\n";
    } else if (balance >= amount) {
        balance -= amount;
        cout << "Amount withdrawn: " << amount << ". New Balance: " << balance << endl << endl;
    } else {
        cout << "Insufficient funds, please select a new amount\n";
    }
}

// Function to output balance
    void getBalance() {
        cout << "Your Current balance is: \n" << balance << endl << endl;;
    
    }
    
};
// Menu for user to select options from 
void Menu() {

    cout << "1. Create Account\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw money\n";
    cout << "4. Check Balance\n";
    cout << "5. Exit\n\n";
    cout << "Enter your preferred choice: \n";

}

int main() {
    srand(time(0)); // Seed for random account numbers

    string name;
    int choice;
    double balance = 0.00, amount; 

    bankaccount account(" ", balance); // the initial empty account

    cout << "Welcome to the bank of syed\n\n";


    while (true) {// loop that keeps the program running until user exits
        try {
            Menu();
            cin >> choice;
            if (cin.fail())
                throw runtime_error("Invalid selection. Please enter a numeric value.");
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear newline
        
    switch(choice) { // runs a switch case to select the option from menu
        case 1:
            cout << "Enter name of the account holder: \n";
            getline(cin, name);
        // valdiates the balance to be non-negative and non numeric 
        while (true) {
            try {
                cout << "Enter initial balance: ";
                cin >> balance;
                // checks validity and throws exception if invalid
                if (cin.fail())
                    throw runtime_error("Invalid balance. Please enter a numeric value.");
                if (balance < 0)
                    throw runtime_error("Invalid balance. Please enter a non-negative number.");
                break; // valid input received
                // catchs the exception and outputs error message
            } catch (exception &e) {
                cout << e.what() << "\n\n";
                // clears cin error flag
                cin.clear();
                 // discard invalid input
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear newline
        account = bankaccount(name, balance); // creates new account
        cout << "Account created successfully\n\n";
            break;

         case 2: //deposit money
            while (true) {
                try {
                    cout << "How much would you like to deposit today: ";
                    cin >> amount;
                    // checks validity and throws exception if invalid
                    if (cin.fail())
                        throw runtime_error("Invalid input, please enter a numeric value.");
                    break; // valid input received
                    // catchs the exception and outputs error message
                } catch (exception &e) {
                    cout << e.what() << "\n\n";
                    // clears cin error flag
                    cin.clear();
                    // discard invalid input
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            account.deposit(amount);
            break;
        case 3: //withdraw money
            while (true) {
                try {
                    cout << "Enter withdrawal amount: ";
                    cin >> amount;
                    // checks validity and throws exception if invalid
                    if (cin.fail())
                        throw runtime_error("Invalid input! Please enter a numeric value.");
                    break; // valid input received
                    // catchs the exception and outputs error message
                } catch (exception &e) {
                    cout << e.what() << "\n\n";
                    // clears cin error flag
                    cin.clear();
                    // discard invalid input
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            account.withdraw(amount);
            break;

        case 4: // show the balance
            account.getBalance();
            break;

        case 5: // exits the program
            cout << "Thank you for banking with us\n";
            return 0;

        default: // invalid input case
            cout << "invalid choice, please select a valid option\n";
            continue; // loop restarts if invalid option is selected
        }
    } catch (exception &e) {
        // catch any exceptions from the main menu and clear input stream
        cout << e.what() << "\n\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
    return 0;
}