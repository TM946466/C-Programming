//Timothy McGowan
//ATM Main File
//CS345-81

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ATMHEAD.h"

#define WLIMIT 1000     //Withdrawal Limit Defined
#define DLIMIT 10000    //Deposit Limit Defined

int main(int argc, char *argv[]){

        int curbal = 5000;      //Nana's current Balance
        int choice = -1;        //Initialize var for user choice
        int moneyamount = -1;   //Initialize var for choice of amount of money for transactions
        int dailywithdraw = 0;  //Initialize Daily withdraw amount to 0
        int dailydeposit = 0;   //Initialize Daily deposit amount to 0
        int transactions = 0;   //Initialize Daily transaction amount to 0
        int attempts = 3;       //Initialize attempt amount to 0


        do{
            printf("Please enter your pin:\n"); //Ask Nana for Pin
            scanf("%d", &choice);
            if(choice == 3014){                 //Verify pin (In a real environment this would be turned to a function to grab server data)
                printf("Welcome Back Nana\n\n");//Welcome message
                choice = -1;                    //Reset choice for future use/functionality
                attempts = 3;                   //Reset choice for future use/functionality
                break;                          //Break out of loop on successful pin entry
            }
            else{                               //Otherwise decrement attempts amount and check to see if attempts are left
                --attempts;
                if(attempts == 0){              //If attempts amount met display farewell message and terminate program
                    printf("Attempt Limit Exceeded Logging out\n\n");
                    exit(0);
                }
                printf("Unrecognized Pin Please Try again\n\n");
                printf("Attempts Remaining: %d\n",attempts);
            }

        }while(choice != 3014); //Continue while choice is not correct (This would check a boolean var if there were multiple users)


        while(choice){//Loop while the users choice exists
            printf("Please choose an option:\n1 - Balance\n2 - Deposit\n3 - Withdraw\n4 - Quit\n");//Menu Options
            scanf("%d", &choice);//Scan for user choice
            if(choice == 2){ //User chooses option 2 DEPOSit
                while(moneyamount < 0){
                        if(dailydeposit >= DLIMIT){//Check if Daily deposit limit is reached
                            --attempts;             //if limit is reached decrement attempts and check if attempt limit is met for ejection
                            if(attempts == 0){
                                printf("Attempt Limit Exceeded Logging out\n\n");
                                exit(0);
                            }
                            printf("Daily Deposit Limit Reached Please Choose another Option\n\n");
                            printf("Attempts Remaining: %d\n",attempts);
                            break;
                        }
                        printf("\nToday You Have Deposited: $%d\n",dailydeposit); //Display total daily deposits
                        printf("Daily Limit: $%d\n",DLIMIT);                      //Display Daily Limit
                        printf("Current Balance: $%d\n\nPlease Enter Amount You Wish To Deposit:\n",curbal); //Display current balance and ask for Deposit ammount
                        scanf("%d",&moneyamount);
                        if(moneyamount <= 0){//Make sure user entry is above 0
                            --attempts;
                            if(attempts == 0){
                                printf("Attempt Limit Exceeded Logging out\n\n");
                                exit(0);
                            }
                            printf("Please Enter An Amount Greater Than 0.\n\n");
                            printf("Attempts Remaining: %d\n",attempts);
                            moneyamount = -1;
                            continue;
                        }
                        else if((moneyamount+dailydeposit) > DLIMIT){//Check to see if current deposit amount will exceed limit
                            --attempts;
                            if(attempts == 0){
                                printf("Attempt Limit Exceeded Logging out\n\n");
                                exit(0);
                            }
                            printf("Transaction will Exceed Daily Limit\nPlease Enter A Lesser Amount\n\n");
                            printf("Attempts Remaining: %d\n",attempts);
                            moneyamount = -1;
                            continue;
                        }
                        else{
                            curbal = deposit(curbal,moneyamount);   //If user entry is good proceed with transaction
                            printf("Would you like a receipt?\n1 - Yes\n2 - No\n\n"); //Prompt for receipt
                            scanf("%d", &choice);
                            if(choice == 1){
                                printf("Printing Receipt...\n\n");
                                choice = -1;
                            }
                            dailydeposit = (dailydeposit + moneyamount); //Adjust daily deposit amount
                            moneyamount = -1;//Reset money amount
                            transactions++; //Increment Total transactions
                            break;          //return to choice menu
                        }


                    }

            continue;
            }
            else if(choice == 1){   //If choice is 1 - BALANCE display balance and prompt for receipt
                        printf("\nCurrent Balance: $%d\n\n",curbal);
                        printf("Would you like a receipt?\n1 - Yes\n2 - No\n\n");
                            scanf("%d", &choice);
                            if(choice == 1){
                                printf("Printing Receipt...\n\n");
                                choice = -1;
                            }
                        continue;
            }
            else if(choice == 3){   //If choice is 3 - Withdraw
                    while(moneyamount < 0){
                        if(dailywithdraw >= WLIMIT){ //Check if withdrawal limit already met
                            --attempts;
                            if(attempts == 0){
                                printf("Attempt Limit Exceeded Logging out\n\n");
                                exit(0);
                            }
                            printf("Daily Withdrawal Limit Reached Please Choose another Option\n\n");
                            printf("Attempts Remaining: %d\n",attempts);
                            break;
                        }
                        printf("\nToday You Have Withdrawn: $%d\n",dailywithdraw); //Display daily withdraw
                        printf("Daily Limit: $%d\n",WLIMIT);                        //Display Daily Limit
                        printf("Current Balance: $%d\n\nPlease Enter Amount You Wish To Withdraw (in $20's):\n",curbal); //Prompt user for entry in 20 dollar multiples
                        scanf("%d",&moneyamount);
                        if(moneyamount <= 0){   //Verify user entered value greater than 0
                            printf("Please Enter An Amount Greater Than 0.\n\n");
                            moneyamount = -1;
                            continue;
                        }
                        else if((moneyamount%20)!= 0){ //Verify User entered a multiple of 20
                            --attempts;
                            if(attempts == 0){  //attempt checker
                                printf("Attempt Limit Exceeded Logging out\n\n");
                                exit(0);
                            }
                            printf("Please Enter A Multiple of 20\n\n"); //Prompt for proper entry
                            printf("Attempts Remaining: %d\n",attempts);
                            moneyamount = -1;
                            continue;
                        }
                        else if((moneyamount+dailywithdraw) > WLIMIT){ //Verify money amount wont exceed daily limit
                            --attempts;
                            if(attempts == 0){
                                printf("Attempt Limit Exceeded Logging out\n\n");
                                exit(0);
                            }
                            printf("Transaction will Exceed Daily Limit\nPlease Enter A Lesser Amount\n\n");
                            printf("Attempts Remaining: %d\n",attempts);
                            moneyamount = -1;
                            continue;
                        }
                        else if(moneyamount > curbal){  //Verify withdrawl amount will not exceed current balance
                            --attempts;
                            if(attempts == 0){
                                printf("Attempt Limit Exceeded Logging out\n\n");
                                exit(0);
                            }
                            printf("Transaction will Exceed Balance\nPlease Enter A Lesser Amount\n\n");
                            printf("Attempts Remaining: %d\n",attempts);
                            moneyamount = -1;
                            continue;
                        }
                        else{   //All verifications met
                            curbal = withdraw(curbal,moneyamount);  //Proceed with transaction function call needed balance and withdrawal amount
                            printf("Would you like a receipt?\n1 - Yes\n2 - No\n\n"); //Prompt for receipt
                            scanf("%d", &choice);
                            if(choice == 1){
                                printf("Printing Receipt...\n\n");
                                choice = -1;
                            }
                            dailywithdraw = (dailywithdraw + moneyamount); //Adjust daily withdrawal amount
                            moneyamount = -1;   //Reset Money amount for future choices
                            transactions++;     //Increment Transaction counter
                            break;
                        }


                    }

                    continue;
            }
            else if(choice == 4){   //User choice is 4 - Quit
                printf("\nNumber Of Transactions: %d\n\nThank You, Goodbye\n",transactions); //Display number of transactions and Farewell Message
                exit(0);
            }
            else{   //Unknown choice removes an attempt and exits if attempt limit is reached
                --attempts;
                if(attempts == 0){
                    printf("Attempt Limit Exceeded Logging out\n\n");
                    exit(0);
                }
                printf("Command Not Recognized Please Enter A Listed Command\n");
                printf("Attempts Remaining: %d\n",attempts);
                continue;
            }



    }
}
