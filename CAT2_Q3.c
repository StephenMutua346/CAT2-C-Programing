#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void writeInputFile();
void processFile();
void displayFiles();

int main() {
    writeInputFile();
    processFile();
    displayFiles();
    return 0;
}

// Function to prompt user for 10 integers and write to input.txt
void writeInputFile() {
    FILE *file;
    int numbers[10];
    int i;
    
    // Open file for writing
    file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("Error: Could not create input.txt file!\n");
        return;
    }
    
    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
        fprintf(file, "%d\n", numbers[i]);
    }
    
    fclose(file);
    printf("10 integers successfully written to input.txt\n\n");
}

// Function to read integers, calculate sum and average, and write to output.txt
void processFile() {
    FILE *inputFile, *outputFile;
    int numbers[10];
    int i, sum = 0;
    float average;
    
    // Open input file for reading
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input.txt for reading!\n");
        return;
    }
    
    // Read numbers from file and calculate sum
    for (i = 0; i < 10; i++) {
        if (fscanf(inputFile, "%d", &numbers[i]) != 1) {
            printf("Error reading integer from input.txt!\n");
            fclose(inputFile);
            return;
        }
        sum += numbers[i];
    }
    fclose(inputFile);
    
    // Calculate average
    average = (float)sum / 10;
    
    // Open output file for writing
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not create output.txt file!\n");
        return;
    }
    
    // Write results to output file
    fprintf(outputFile, "Sum: %d\n", sum);
    fprintf(outputFile, "Average: %.2f\n", average);
    fclose(outputFile);
    
    printf("Results successfully written to output.txt\n\n");
}

// Function to display contents of both files
void displayFiles() {
    FILE *inputFile, *outputFile;
    int numbers[10];
    int i;
    char line[100];
    
    // Display input.txt contents
    printf("=== CONTENTS OF input.txt ===\n");
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input.txt for reading!\n");
        return;
    }
    
    for (i = 0; i < 10; i++) {
        if (fscanf(inputFile, "%d", &numbers[i]) == 1) {
            printf("Number %d: %d\n", i + 1, numbers[i]);
        }
    }
    fclose(inputFile);
    
    // Display output.txt contents
    printf("\n=== CONTENTS OF output.txt ===\n");
    outputFile = fopen("output.txt", "r");
    if (outputFile == NULL) {
        printf("Error: Could not open output.txt for reading!\n");
        return;
    }
    
    while (fgets(line, sizeof(line), outputFile) != NULL) {
        printf("%s", line);
    }
    fclose(outputFile);
}