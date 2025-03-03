#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Account.h"
#include "Types.h"
#include "Transactions.h"
#include "include.h"

Transaction *Thead = NULL;
Transaction *Helpadd = NULL;
Transaction *HelpDisplay = NULL;
void Trasactions()
{
    printf("1-Process Transactions.     2-Display Transactions. \n ");
    u32 Tchoice;scanf("%d", &Tchoice);
    switch(Tchoice)
    {
    case 1:
        process_transaction();
        break;
    case 2:
        display_transactions();
        break;
    }
}
void process_transaction()
{
    printf("Enter the sender name : ");
    u8 sender[MAX_LENGTH]; scanf("%s", &sender);
    u32 flag = AccountSearching(sender);
    if(flag == 0)
        printf("There is no account with that name!");
    else
    {
        printf("Enter the receiver's name : ");
        u8 receiver[MAX_LENGTH]; scanf("%s", &receiver);
        u32 flag2 = AccountSearching(receiver);
        if(flag2 == 0 )
            printf("There is no account with that name!");
        else
        {
            printf("Enter the amount : ");
            u32 amount; scanf("%d", &amount);
            Transaction *NewNode = (Transaction*)malloc(sizeof(Transaction));
            if(NewNode == NULL)
            {
                printf("The transaction failed");
            }
            else
            {
                if(Thead == NULL)
                    Thead = NewNode;
                else
                {
                    Helpadd = Thead;
                    while(Helpadd->next != NULL)
                        Helpadd = Helpadd->next;
                    Helpadd->next = NewNode;
                    NewNode->next = NULL;
                }
                strcpy(NewNode->receiver,receiver);
                strcpy(NewNode->sender,sender);
                NewNode->amount = amount;
                ProcessingTransaction(sender,receiver,amount);
                FILE *file = fopen("Transactions.csv", "a");
                if (file == NULL) {
                    printf("                                            Error opening file.\n");
                }
                else
                {
                    fprintf(file, "%s,%s,%d\n", NewNode->sender , NewNode->receiver , NewNode->amount);
                    fclose(file);
                }
            }
        }
    }
}
void display_transactions()
{
    FILE *file = fopen("Transactions.csv", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
    }
    else
    {
        char line[200];
        while (fgets(line, sizeof(line), file)) {
            Transaction *newTransaction = (Transaction *)malloc(sizeof(Transaction));
            if (newTransaction == NULL) {
                printf("Memory allocation failed.\n");
            }
            else
            {
                sscanf(line, "%99[^,],%99[^,],%d\n", newTransaction->sender, newTransaction->receiver, &newTransaction->amount);
                newTransaction->next = Thead;
                Thead = newTransaction;
            }
        }
        fclose(file);
    }
    printf("Enter Your name :");
    u8 name[MAX_LENGTH];scanf("%s", &name);
    HelpDisplay = Thead;
    u32 flag = 0;
    while(HelpDisplay != NULL)
    {
        if((!(strcmp(HelpDisplay->sender,name))) || (!(strcmp(HelpDisplay->receiver,name))))
        {
            flag = 1;
            printf("The transactions : \n");
            printf("sender is %s \treceiver is %s \tamount is %d \n",HelpDisplay->sender ,HelpDisplay->receiver ,HelpDisplay->amount);
        }
        HelpDisplay = HelpDisplay->next;
    }
    if(flag == 0)
        printf("There is no transactions in that account\n");
}
