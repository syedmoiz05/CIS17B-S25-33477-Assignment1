# Simple Banking System

Welcome to my simple C++ banking system! This program allows you to:
- Create a bank account (with a name and initial balance).
- Deposit money into your account.
- Withdraw money from your account.
- Check your current balance.
- Exit the program when you’re done.

It’s designed as a console application and uses basic exception handling to prevent invalid input (like typing letters when a number is expected).

---

## How to Compile and Run

1. **Clone or Download the Repository**  
   - If you have Git installed, you can clone the repository by opening your terminal (or Git Bash) and typing:
     ```bash
     git clone https://github.com/your-username/CS1570-528-33477-Assignment.git
     ```
   - Alternatively, you can download the repository as a ZIP file from GitHub and extract it on your machine.

2. **Navigate to the Project Folder**  
   - Open your terminal or command prompt.
   - Use `cd` (change directory) to move into the folder that contains `main.cpp`.

3. **Compile the Code**  
   - Use a C++ compiler 
     ```bash
     g++ main.cpp 
     ```
   - This command will compile `main.cpp

4. **Run the Program**  
   - After compilation, run:
     ```bash
     ./bankingSystem
     ```
    

5. **Follow the On-Screen Menu**  
   - You will see a menu with several options.  
   - Type the number in relation to the action you want to take (e.g., 1 to create an account, 2 to deposit, etc.), then press **Enter**.  
   - If you enter an invalid option or type a non-numeric value, the program will ask you to try again.

---

## Program Features

1. **Create an Account**  
   - Prompts you for an account holder’s name.  
   - Prompts for an initial balance, which must be a **non-negative** number.  
   - Generates a random account number.

2. **Deposit**  
   - Asks how much you want to deposit.  
   - Ensures you type a valid numeric value.  
   - Updates the balance if valid.

3. **Withdraw**  
   - Asks how much you want to withdraw.  
   - Checks if you have enough balance.  
   - If there’s insufficient funds, it will notify you.

4. **Check Balance**  
   - Shows your current balance on the screen.

5. **Exit**  
   - Closes the program with a goodbye message.

---

## Code Explanation

1. **`bankaccount` Class**  
   - **Private Members**: `accountHolderName`, `accountNumber`, `balance`.  
   - **Constructor**: Initializes the name and balance, generates a random account number.  
   - **Methods**:
     - `deposit(double amount)`: Increases the balance if the amount is positive.  
     - `withdraw(double amount)`: Decreases the balance if you have enough funds and if the amount is positive.  
     - `getBalance()`: Displays the current balance.

2. **`Menu()` Function**  
   - Prints out the list of actions the user can perform.

3. **`main()` Function**  
   - Contains a `while(true)` loop that keeps showing the menu until you select “Exit.”  
   - Uses `try-catch` blocks to handle invalid numeric inputs (for example, if you type letters instead of numbers).  
   - Uses a `switch` statement to perform actions based on the user’s choice:
     - **Case 1**: Create a new account.  
     - **Case 2**: Deposit money.  
     - **Case 3**: Withdraw money.  
     - **Case 4**: Check balance.  
     - **Case 5**: Exit the program.

---


