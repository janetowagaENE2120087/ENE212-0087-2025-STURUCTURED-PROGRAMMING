#include <stdio.h>
#include <string.h>

//definition
//login function
int login(char username[50], char pin[5]) {
    char correctusername[50] = "Ruette";
    char correctpin[] = "0104";
    if (strcmp(correctusername, username) == 0 && strcmp(correctpin, pin) == 0) {
        return 1; //success
    }
    return 0; //fail
}

//display menu function
void displaymenu() {
    printf("\nENTER YOUR CHOICE OF SERVICE\n");
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
}

//checkbalance function
void Checkbalance(double balance) {
    printf("Account Balance is: Ksh%.2f\n", balance);
}

//deposit function
void depositmoney(double *balance) {
    double amount;
    printf("\nEnter amount to deposit:Ksh");
    scanf("%lf", &amount);
    if (amount > 0) {
        *balance = *balance + amount;
        printf("\nDeposit done\n");
        printf("New balance is: ksh %.2f\n", *balance);
    } else {
        printf("\nInvalid deposit amount\n");
    }
}

//withdrawal function
void withdrawmoney(double *balance) {
    double amount;
    printf("\nEnter amount to withdraw");
    scanf("%lf", &amount);
    if (amount <= 0) {
        printf("Invalid withdrawal amount\n");
    } else if (amount > *balance) {
        printf("Insufficient balance\n");
    } else {
        *balance = *balance - amount;
        printf("Amount withdrawn: Ksh%.2lf\n", amount);
        printf("new Balance: Ksh%.2lf\n", *balance);
    }
}

int main() {
    //function declaration
    char username[50];
    char pin[5];
    double balance = 7000.00;
    int choice;

    printf("Enter username");
    scanf("%49s", username);
    printf("Enter pin");
    scanf("%4s", pin);

    //function call
    //call login
    int result = login(username, pin);
    if (result == 1) {
        do {
            //display menu call
            displaymenu();
            scanf("%d", &choice);
            //user's choice
            if (choice == 1) {
                Checkbalance(balance);
            }
            else if (choice == 2) {
                depositmoney(&balance);
            }
            else if (choice == 3) {
                withdrawmoney(&balance);
            } else if (choice == 4) {
                printf("Thankyou\n");
            } else {
                printf("invalid choice\n");
            }
        } while (choice != 4);
    }
    else {
        printf("invalid username or pin");
    }
    return 0;
}
