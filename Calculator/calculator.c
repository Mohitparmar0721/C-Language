#include <stdio.h>
#include <conio.h>
void main()
{
    int no1, no2, result, choice;
    puts("1. Addition");
    puts("2. Subtraction");
    puts("3. Multification");
    puts("4. Divition");
    puts("5. Exit");
    puts("Enter your choice : ");
    scanf("%d", &choice);
    puts("Enter first Number : ");
    scanf("%d", &no1);
    puts("Enter Second Number : ");
    scanf("%d", &no2);
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
        result = no1 % no2;
        printf("%d / %d = %d\n", no1, no2, result);
        break;

    case 5:
        return;
    }
    return;
}