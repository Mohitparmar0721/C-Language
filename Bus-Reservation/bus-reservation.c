#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUSES 5  // Maximum number of buses allowed
#define MAX_SEATS 40 // Maximum number of seats per bus

// Structure to store bus information
struct Bus
{
    int id;               // Bus ID
    char name[50];        // Bus name
    int availableSeats;   // Number of available seats
    int seats[MAX_SEATS]; // Array to store seat reservation status (0 = available, 1 = reserved)
};

// Array to store buses
struct Bus buses[MAX_BUSES];
int busCount = 0; // Counter for total buses

// Function to add a new bus
void addBus()
{
    if (busCount >= MAX_BUSES)
    {
        printf("Cannot add more buses. The list is full.\n");
        return;
    }
    struct Bus newBus;
    printf("Enter Bus ID: ");
    scanf("%d", &newBus.id);
    printf("Enter Bus Name: ");
    scanf("%s", newBus.name);
    newBus.availableSeats = MAX_SEATS;

    // Initialize all seats as available
    for (int i = 0; i < MAX_SEATS; i++)
    {
        newBus.seats[i] = 0;
    }

    // Add the new bus to the list
    buses[busCount++] = newBus;
    printf("Bus added successfully!\n");
}

// Function to display all available buses
void displayBuses()
{
    if (busCount == 0)
    {
        printf("No buses to display.\n");
        return;
    }
    printf("ID\tName\t\tAvailable Seats\n");
    printf("---------------------------------\n");
    for (int i = 0; i < busCount; i++)
    {
        printf("%d\t%s\t\t%d\n", buses[i].id, buses[i].name, buses[i].availableSeats);
    }
}

// Function to reserve a seat on a bus
void reserveSeat()
{
    int busId, seatNumber;
    printf("Enter Bus ID: ");
    scanf("%d", &busId);

    struct Bus *selectedBus = NULL;

    // Find the bus with the given ID
    for (int i = 0; i < busCount; i++)
    {
        if (buses[i].id == busId)
        {
            selectedBus = &buses[i];
            break;
        }
    }

    if (selectedBus == NULL)
    {
        printf("Bus with ID %d not found.\n", busId);
        return;
    }

    if (selectedBus->availableSeats == 0)
    {
        printf("No available seats on this bus.\n");
        return;
    }

    printf("Enter Seat Number (1-%d): ", MAX_SEATS);
    scanf("%d", &seatNumber);

    // Check if the seat is valid and available
    if (seatNumber < 1 || seatNumber > MAX_SEATS || selectedBus->seats[seatNumber - 1] == 1)
    {
        printf("Invalid seat number or seat already reserved.\n");
        return;
    }

    // Reserve the seat
    selectedBus->seats[seatNumber - 1] = 1;
    selectedBus->availableSeats--;
    printf("Seat %d reserved successfully on bus %s.\n", seatNumber, selectedBus->name);
}

// Function to cancel a reserved seat
void cancelReservation()
{
    int busId, seatNumber;
    printf("Enter Bus ID: ");
    scanf("%d", &busId);

    struct Bus *selectedBus = NULL;

    // Find the bus with the given ID
    for (int i = 0; i < busCount; i++)
    {
        if (buses[i].id == busId)
        {
            selectedBus = &buses[i];
            break;
        }
    }

    if (selectedBus == NULL)
    {
        printf("Bus with ID %d not found.\n", busId);
        return;
    }

    printf("Enter Seat Number (1-%d): ", MAX_SEATS);
    scanf("%d", &seatNumber);

    // Check if the seat number is valid and reserved
    if (seatNumber < 1 || seatNumber > MAX_SEATS || selectedBus->seats[seatNumber - 1] == 0)
    {
        printf("Invalid seat number or seat not reserved.\n");
        return;
    }

    // Cancel the reservation
    selectedBus->seats[seatNumber - 1] = 0;
    selectedBus->availableSeats++;
    printf("Seat %d reservation canceled successfully on bus %s.\n", seatNumber, selectedBus->name);
}

// Main function to handle user input and menu system
int main()
{
    int choice;
    while (1)
    {
        printf("\nBus Reservation System\n");
        printf("1. Add Bus\n");
        printf("2. Display Buses\n");
        printf("3. Reserve Seat\n");
        printf("4. Cancel Reservation\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBus(); // Add new bus
            break;
        case 2:
            displayBuses(); // Display all buses
            break;
        case 3:
            reserveSeat(); // Reserve a seat
            break;
        case 4:
            cancelReservation(); // Cancel a reservation
            break;
        case 5:
            exit(0); // Exit the program
        default:
            printf("Invalid choice. Please try again.\n"); // Handle invalid input
        }
    }
    return 0;
}
