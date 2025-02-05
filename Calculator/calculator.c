#include <stdio.h>

int main()
{
    int no1, no2, result, choice;

    // Display Menu
    puts("1. Addition");
    puts("2. Subtraction");
    puts("3. Multiplication");
    puts("4. Division");
    puts("5. Exit");

    // Get user choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // If user chooses to exit
    if (choice == 5)
    {
        return 0;
    }

    // Get two numbers from user
    printf("Enter first number: ");
    scanf("%d", &no1);
    printf("Enter second number: ");
    scanf("%d", &no2);

    // Perform operation based on choice
    switch (choice)
    {
    case 1:
        result = no1 + no2;
        printf("%d + %d = %d\n", no1, no2, result);
        break;

    case 2:
        result = no1 - no2;
        printf("%d - %d = %d\n", no1, no2, result);
        break;

    case 3:
        result = no1 * no2;
        printf("%d * %d = %d\n", no1, no2, result);
        break;

    case 4:
        if (no2 == 0)
        {
            printf("Error! Division by zero is not allowed.\n");
        }
        else
        {
            float div_result = (float)no1 / no2; // Use float for accurate division
            printf("%d / %d = %.2f\n", no1, no2, div_result);
        }
        break;

    default:
        printf("Invalid choice! Please enter a number between 1 and 5.\n");
    }

    return 0;
}
