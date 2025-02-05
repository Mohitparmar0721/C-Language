#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100 // Maximum number of attendance records
#define MAX_NAME_LEN 50 // Maximum length of name

// Structure for storing attendance record
struct AttendanceRecord
{
    int id;                  // ID of the student
    char name[MAX_NAME_LEN]; // Name of the student
    int isPresent;           // 1 for present, 0 for absent
};

// Array to store attendance records
struct AttendanceRecord records[MAX_RECORDS];
int recordCount = 0; // Variable to keep track of the number of records

// Function to add a new attendance record
void addRecord()
{
    if (recordCount >= MAX_RECORDS)
    {
        printf("Cannot add more records. The list is full.\n");
        return;
    }
    struct AttendanceRecord newRecord;
    printf("Enter ID: ");
    scanf("%d", &newRecord.id);
    printf("Enter Name: ");
    scanf("%s", newRecord.name);
    printf("Enter 1 for Present or 0 for Absent: ");
    scanf("%d", &newRecord.isPresent);
    records[recordCount++] = newRecord;
    printf("Record added successfully!\n");
}

// Function to display all attendance records
void displayRecords()
{
    if (recordCount == 0)
    {
        printf("No records to display.\n");
        return;
    }
    printf("ID\tName\t\tStatus\n");
    printf("----------------------------\n");
    for (int i = 0; i < recordCount; i++)
    {
        printf("%d\t%s\t\t%s\n", records[i].id, records[i].name, records[i].isPresent ? "Present" : "Absent");
    }
}

// Function to search for a record by ID
void searchRecord()
{
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < recordCount; i++)
    {
        if (records[i].id == id)
        {
            printf("Record found:\n");
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("Status: %s\n", records[i].isPresent ? "Present" : "Absent");
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

// Function to delete a record by ID
void deleteRecord()
{
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < recordCount; i++)
    {
        if (records[i].id == id)
        {
            for (int j = i; j < recordCount - 1; j++)
            {
                records[j] = records[j + 1]; // Shift remaining records
            }
            recordCount--; // Decrease the record count
            printf("Record with ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

// Main function to drive the system
int main()
{
    int choice;
    while (1)
    {
        printf("\nAttendance Monitoring System\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addRecord(); // Add new record
            break;
        case 2:
            displayRecords(); // Display all records
            break;
        case 3:
            searchRecord(); // Search for a record
            break;
        case 4:
            deleteRecord(); // Delete a record
            break;
        case 5:
            exit(0); // Exit the program
        default:
            printf("Invalid choice. Please try again.\n"); // Invalid input handling
        }
    }
    return 0;
}
