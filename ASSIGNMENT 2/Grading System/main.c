#include <stdio.h>

#define UNITS 4

void printGrade(float mark)
{
    if (mark >= 70)
        printf("A - Excellent\n");
    else if (mark >= 60)
    printf("B - Good\n");
    else if (mark >= 50)
     printf("C - Average\n");
    else if (mark >= 40)
    printf("D - Pass\n");
    else
     printf("E - Fail\n");
}

int main()
{
    const char *units[UNITS] = {"Calculus", "ODEs", "Programming", "Circuit Analysis"};
    float marks[UNITS];
    float total = 0;
    int i;

    for (i = 0; i < UNITS; i++) {
        do {
            printf("Enter score for %s (0-100): ", units[i]);
            scanf("%f", &marks[i]);
            if (marks[i] < 0 || marks[i] > 100)
                printf("Invalid score. Try again.\n");
        } while (marks[i] < 0 || marks[i] > 100);

        total += marks[i];
    }

    printf("\n--- Results ---\n");
    for (i = 0; i < UNITS; i++) {
        printf("%-18s %6.1f   ", units[i], marks[i]);
        printGrade(marks[i]);
    }

    float average = total / UNITS;
    printf("\nAverage: %.2f   ", average);
    printGrade(average);

    return 0;
}
