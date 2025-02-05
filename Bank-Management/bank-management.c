#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for BankAccount
struct BankAccount
{
    int account_no; // Account number
    char name[50];  // Account holder's name
    float balance;  // Account balance
};

// Function prototypes
void createAccount(struct BankAccount *accounts, int *count);
void deposit(struct BankAccount *accounts, int count);
void withdraw(struct BankAccount *accounts, int count);
void displayAccounts(struct BankAccount *accounts, int count);

int main()
{
    struct BankAccount accounts[100]; // Array of bank accounts
    int count = 0;                    // To track the number of accounts
    int choice;

    while (1)
    {
        // Menu for user to select an option
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Accounts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch case to handle menu options
        switch (choice)
        {
        case 1:
            createAccount(accounts, &count); // Create a new account
            break;
        case 2:
            deposit(accounts, count); // Deposit money into an account
            break;
        case 3:
            withdraw(accounts, count); // Withdraw money from an account
            break;
        case 4:
            displayAccounts(accounts, count); // Display all accounts
            break;
        case 5:
            exit(0); // Exit the program
            break;
        default:
            printf("Invalid choice! Please try again.\n"); // Invalid choice message
        }
    }

    return 0;
}

// Function to create a new bank account
void createAccount(struct BankAccount *accounts, int *count)
{
    // Get account number, name, and initial deposit from the user
    printf("Enter Account Number: ");
    scanf("%d", &accounts[*count].account_no);
    getchar(); // Consume the newline character left by scanf

    // Input the account holder's name
    printf("Enter Account Holder Name: ");
    fgets(accounts[*count].name, sizeof(accounts[*count].name), stdin);
    accounts[*count].name[strcspn(accounts[*count].name, "\n")] = 0; // Remove newline character

    // Input the initial deposit amount
    printf("Enter Initial Deposit Amount: ");
    scanf("%f", &accounts[*count].balance);

    // Increment account count and confirm account creation
    (*count)++;
    printf("Account created successfully!\n");
}

// Function to deposit money into an account
void deposit(struct BankAccount *accounts, int count)
{
    int account_no;
    float amount;

    // Get the account number to deposit money into
    printf("Enter Account Number: ");
    scanf("%d", &account_no);

    // Search for the account and deposit money
    for (int i = 0; i < count; i++)
    {
        if (accounts[i].account_no == account_no)
        {
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount; // Update balance
            printf("Amount deposited successfully! New Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    // If account number is not found
    printf("Account with Account Number %d not found.\n", account_no);
}

// Function to withdraw money from an account
void withdraw(struct BankAccount *accounts, int count)
{
    int account_no;
    float amount;

    // Get the account number to withdraw money from
    printf("Enter Account Number: ");
    scanf("%d", &account_no);

    // Search for the account and withdraw money
    for (int i = 0; i < count; i++)
    {
        if (accounts[i].account_no == account_no)
        {
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);

            // Check for sufficient balance
            if (amount > accounts[i].balance)
            {
                printf("Insufficient balance!\n");
            }
            else
            {
                accounts[i].balance -= amount; // Update balance
                printf("Amount withdrawn successfully! New Balance: %.2f\n", accounts[i].balance);
            }
            return;
        }
    }

    // If account number is not found
    printf("Account with Account Number %d not found.\n", account_no);
}

// Function to display all the bank accounts
void displayAccounts(struct BankAccount *accounts, int count)
{
    // If no accounts are available, print a message
    if (count == 0)
    {
        printf("No accounts found.\n");
        return;
    }

    // Display account details for each account
    for (int i = 0; i < count; i++)
    {
        printf("\nAccount Number: %d\n", accounts[i].account_no);
        printf("Account Holder Name: %s\n", accounts[i].name);
        printf("Balance: %.2f\n", accounts[i].balance);
    }
}
