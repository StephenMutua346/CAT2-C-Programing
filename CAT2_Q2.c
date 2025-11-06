/*
Name: Stephen Mutinda Mutua 
Registration number: CT101/G/26532/25
Unit: Introduction To Programming And Problem Solving 
Description: A program to calculate weekly pay, taxes, and net pay.
*/

#include <stdio.h>

int main() {
    // Variable declarations
    int days[7];          // To store hours worked each day
    int k;                // Loop counter
    int totalHours = 0;   // Total hours worked in the week
    float wage;           // Hourly wage
    float grossPay;       // Gross pay before tax
    float taxes;          // Taxes to be deducted
    float netPay;         // Final net pay after tax

    // hii ndiyo Input section
    printf("Kindly enter the hours worked each day of the week:\n");
    for (k = 0; k < 7; k++) {
        printf("Day %d: ", k + 1);
        scanf("%d", &days[k]);
        totalHours += days[k]; // Accumulated total hours ni ngapi?
    }

    // Ask for hourly wage
    printf("Enter your hourly wage: ");
    scanf("%f", &wage);

    // Calculate gross pay with overtime
    if (totalHours <= 40) {
        grossPay = totalHours * wage;
    } else {
        // Overtime pay = 1.5 times normal rate for hours beyond 40
        grossPay = (40 * wage) + ((totalHours - 40) * wage * 1.5);
    }

    // Calculate taxes
    if (grossPay <= 600) {
        taxes = grossPay * 0.15;  // 15% tax on all if <= 600
    } else {
        taxes = (600 * 0.15) + ((grossPay - 600) * 0.20);  // 15% on first 600, 20% on rest
    }

    // Calculate net pay
    netPay = grossPay - taxes;

    // Output section
    printf("\n      Weekly Pay Summary     \n");
    printf("Total Hours Worked: %d\n", totalHours);
    printf("Gross Pay: %.2f\n", grossPay);
    printf("Taxes: %.2f\n", taxes);
    printf("Net Pay: %.2f\n", netPay);

    return 0;
}