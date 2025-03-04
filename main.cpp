#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>



// class for the bank account 
class bankaccount {
    private:
    string accountHolderName;
    int accountNumber;
    double balance;
    public:

    // Funtion to initialize the account
    bankaccount(string name, double initialBalance) {
        accountHolderName = name;
        accountNumber = 0; 
        balance = initialBalance;
    }

    // Function to deposit money, checks for validity and outputs new balance
void deposit(double amount) {
    if (amount > 0) {
        balance += amount; 
        cout << "Amount deposited: " << amount << ". New balance: " << balance << endl;
    } else {
        cout << "Invalid amount, please select a new amount\n";
    }
}
// Function to withdraw money, checks for validity and outputs new balance
void withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        cout << "Amount withdrawn: " << amount << ". New Balance: " << balance << endl;
    } else {
        cout << "Insufficient balance, Please select new amount\n";
    }
 }

// Function to output balance
    void getBalance() {
        cout << "Your Current balance is: " << balance << endl;
    
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

    string name;
    int choice;
    double balance = 1000.00 , amount; 

    bankaccount account(" ", balance); // the initial empty account

    cout << "Welcome to the bank of syed\n";


    do{  // loop that keeps the program running until user exits
        Menu(); // displays the meny options
        cin >> choice;
        
        switch(choice) { // runs a switch case to select the option from menu
            case 1:
            cout << "Enter name of the account holder: ";
            cin.ignore();
            getline(cin, name);
            account = bankaccount(name, balance); // creates a new account
            break;
            case 2:
            cout << "How much would you like to deposit today: ";
            cin >> amount;
            account.deposit(amount);
            break;
            case 3:
            cout << "How much would you like to withdraw today: ";
            cin >> amount;
            account.withdraw(amount);
            break;
            case 4: 
            account.getBalance();
            break;
            case 5: 
            cout << "Thank you for banking with us\n";
            return 0;
            break;
            default:
            cout << "invalid choice, please select a valid option\n";
            continue; // loop restarts if invalid option is selected
        }
    } while (true);



    return 0;
}