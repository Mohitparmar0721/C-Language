#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100 // Maximum number of contacts that can be stored

// Structure to store contact details
struct Contact
{
    int id;         // Unique ID for the contact
    char name[50];  // Contact name
    char phone[15]; // Phone number
    char email[50]; // Email address
};

// Array to store contacts
struct Contact contacts[MAX_CONTACTS];
int contactCount = 0; // Counter to keep track of total contacts

// Function to add a new contact
void addContact()
{
    if (contactCount >= MAX_CONTACTS)
    { // Check if contact list is full
        printf("Cannot add more contacts. The list is full.\n");
        return;
    }
    struct Contact newContact;

    // Get contact details from the user
    printf("Enter Contact ID: ");
    scanf("%d", &newContact.id);
    printf("Enter Contact Name: ");
    scanf("%s", newContact.name);
    printf("Enter Contact Phone: ");
    scanf("%s", newContact.phone);
    printf("Enter Contact Email: ");
    scanf("%s", newContact.email);

    // Store the new contact in the array
    contacts[contactCount++] = newContact;
    printf("Contact added successfully!\n");
}

// Function to display all contacts
void displayContacts()
{
    if (contactCount == 0)
    { // Check if there are any contacts
        printf("No contacts to display.\n");
        return;
    }
    printf("ID\tName\t\tPhone\t\tEmail\n");
    printf("---------------------------------------------\n");

    // Loop through contacts and display them
    for (int i = 0; i < contactCount; i++)
    {
        printf("%d\t%s\t\t%s\t\t%s\n", contacts[i].id, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

// Function to search for a contact by ID
void searchContact()
{
    int id;
    printf("Enter Contact ID to search: ");
    scanf("%d", &id);

    // Loop through contacts to find the matching ID
    for (int i = 0; i < contactCount; i++)
    {
        if (contacts[i].id == id)
        {
            printf("Contact found:\n");
            printf("ID: %d\n", contacts[i].id);
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            return;
        }
    }
    printf("Contact with ID %d not found.\n", id);
}

// Function to delete a contact by ID
void deleteContact()
{
    int id;
    printf("Enter Contact ID to delete: ");
    scanf("%d", &id);

    // Find the contact and remove it
    for (int i = 0; i < contactCount; i++)
    {
        if (contacts[i].id == id)
        {
            // Shift contacts to fill the gap
            for (int j = i; j < contactCount - 1; j++)
            {
                contacts[j] = contacts[j + 1];
            }
            contactCount--;
            printf("Contact with ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("Contact with ID %d not found.\n", id);
}

// Main function to handle user input and menu system
int main()
{
    int choice;
    while (1)
    {
        // Display menu options
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Execute corresponding function based on user input
        switch (choice)
        {
        case 1:
            addContact(); // Add a new contact
            break;
        case 2:
            displayContacts(); // Display all contacts
            break;
        case 3:
            searchContact(); // Search for a contact
            break;
        case 4:
            deleteContact(); // Delete a contact
            break;
        case 5:
            exit(0); // Exit the program
        default:
            printf("Invalid choice. Please try again.\n"); // Handle invalid input
        }
    }
    return 0;
}
