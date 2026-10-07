#include <stdio.h>
#include <stdlib.h>

int main()
{
   #include <stdio.h>


    int Correct_pin = 9999;
    int UserPin;
    int attempts = 0;
    int max_attempts = 3;

    while (attempts < max_attempts) {
        printf("Enter UserPin: ");
        scanf("%d", &UserPin);

        if (UserPin == Correct_pin) {
            printf("ACCESS GRANTED, DOOR UNLOCKED.\n");
            return 0;               // success, leave the program
        }
        else if (UserPin < 1000 || UserPin > 9999) {
            printf("Provide a 4 digit PIN.\n");
        }
        else {
            printf("ACCESS DENIED.\n");
        }

        attempts++;                 // count the failed try
    }

    printf("TOO MANY ATTEMPTS. SYSTEM LOCKED.\n");

    return 0;
}
