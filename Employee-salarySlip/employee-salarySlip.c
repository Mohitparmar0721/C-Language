#include <stdio.h>

// Structure to store employee details
struct Employee
{
    int id;             // Employee ID
    char name[50];      // Employee Name
    float basic_salary; // Employee Basic Salary
    float allowances;   // Employee Allowances
    float deductions;   // Employee Deductions
};

// Function to generate and print the salary slip
void generateSalarySlip(struct Employee emp)
{
    // Calculate net salary after adding allowances and subtracting deductions
    float net_salary = emp.basic_salary + emp.allowances - emp.deductions;

    // Print the formatted salary slip
    printf("********************************\n");
    printf("        Salary Slip             \n");
    printf("********************************\n");
    printf("Employee ID   : %d\n", emp.id);
    printf("Employee Name : %s\n", emp.name);
    printf("Basic Salary  : %.2f\n", emp.basic_salary);
    printf("Allowances    : %.2f\n", emp.allowances);
    printf("Deductions    : %.2f\n", emp.deductions);
    printf("Net Salary    : %.2f\n", net_salary);
    printf("********************************\n");
}

int main()
{
    // Declare an employee structure variable
    struct Employee emp;

    // Get employee details from user input
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter Employee Name: ");
    scanf("%s", emp.name);

    printf("Enter Basic Salary: ");
    scanf("%f", &emp.basic_salary);

    printf("Enter Allowances: ");
    scanf("%f", &emp.allowances);

    printf("Enter Deductions: ");
    scanf("%f", &emp.deductions);

    // Call the function to generate salary slip
    generateSalarySlip(emp);

    return 0;
}
