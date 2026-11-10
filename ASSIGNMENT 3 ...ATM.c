#include <stdio.h>
#include <string.h>

//definition
//login function
int login(char accountnumber[11], char pin[5]) {
    char correctaccount[11] = "0123456789";
    char correctpin[] = "2004";
    if (strcmp(correctaccount,accountnumber ) == 0 && strcmp(correctpin, pin) == 0) {
        return 1; //success
    }
    return 0; //fail
}

//display menu function
void displaymenu() {
    printf("\nPLEASE SELECT YOUR CHOICE OF SERVICE\n");
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
}

//checkbalance function
void Checkbalance(double balance) {
    printf("Your Account Balance is: Ksh%.2f\n", balance);
}

//deposit function
void depositmoney(double *balance) {
    double amount;
    printf("\nPlease Enter amount of money to be deposited:Ksh");
    scanf("%lf", &amount);
    if (amount > 0) {
        *balance = *balance + amount;
        printf("\nWell Deposited\n");
        printf("Your New balance is: ksh %.2f\n", *balance);
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
    char accountnumber[11];
    char pin[5];
    double balance = 20000.00;
    int choice;

    printf("Enter accountnumber");
    scanf("%49s", accountnumber);
    printf("Enter pin");
    scanf("%4s", pin);

    //function call
    //call login
    int result = login(accountnumber, pin);
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
                printf("Thank you for using our ATM\n");
            } else {
                printf("invalid choice\n");
            }
        } while (choice != 4);
    }
    else {
        printf("invalid accountnumber or pin");
    }
    return 0;
}
