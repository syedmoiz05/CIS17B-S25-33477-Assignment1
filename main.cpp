#include <iostream>
using namespace std;

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
        cout << "Amount deposited: " << amount << "New balance: " << balance << endl;
    } else {
        cout << "Invalid amount, please select a new amount\n";
    }
}
// Function to withdraw money, checks for validity and outputs new balance
void withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        cout << "Amount withdrawn: " << amount << "New amount: " << balance << endl;
    } else
     ( cout << "Insufficient balance, Please select new amount\n");
    }

// Function to output balance
    void getBalance() {
        cout << "Your Current balance is: " << balance << endl;
    
    }
    
}

Void Menu() {

    cout << "1. Create Account\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw money\n";
    cout << "4. Check Balance\n";
    cout << "5. Exit\n";
    cout << "Enter your preferred choice: ";

}

int main() {

    int choice;





    return 0;
}