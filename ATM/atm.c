#include <stdio.h>

int th = 1000, tt = 1000, tf = 1000, ttt = 1000; // Global variables

int main()
{
    int rs100, rs200, rs500, rs2000, amount; // Local variables
    long int avlmoney;

    // User input for amount
    puts("Enter amount: ");
    scanf("%d", &amount);

    // Check if the entered amount is a multiple of 100
    if (amount % 100 != 0)
    {
        puts("Error: You have entered an invalid amount!");
        return 0;
    }

    avlmoney = th * 100 + tt * 200 + tf * 500 + ttt * 2000;

    // Check if the requested amount is greater than the available funds
    if (amount > avlmoney)
    {
        puts("Sorry! Insufficient funds.");
        return 0;
    }

    // Check the 2000 rupee currency note
    rs2000 = amount / 2000;
    if (rs2000 > ttt)
    {
        rs2000 = ttt;
    }
    ttt = ttt - rs2000;
    amount = amount - rs2000 * 2000;

    // Check the 500 rupee currency note
    rs500 = amount / 500;
    if (rs500 > tf)
    {
        rs500 = tf;
    }
    tf = tf - rs500;
    amount = amount - rs500 * 500;

    // Check the 200 rupee currency note
    rs200 = amount / 200;
    if (rs200 > tt)
    {
        rs200 = tt;
    }
    tt = tt - rs200;
    amount = amount - rs200 * 200;

    // Check the 100 rupee currency note
    rs100 = amount / 100;
    if (rs100 > th)
    {
        rs100 = th;
    }
    th = th - rs100;
    amount = amount - rs100 * 100;

    // If the amount is not 0, the transaction has failed
    if (amount > 0)
    {
        puts("Error: Transaction failed. Please try again!");
        ttt = ttt + rs2000;
        tf = tf + rs500;
        tt = tt + rs200;
        th = th + rs100;
        return 0;
    }

    // If the amount is successfully processed, print the breakdown
    printf("2000 * %d = %d\n", rs2000, rs2000 * 2000);
    printf("500 * %d = %d\n", rs500, rs500 * 500);
    printf("200 * %d = %d\n", rs200, rs200 * 200);
    printf("100 * %d = %d\n", rs100, rs100 * 100);

    return 0;
}
