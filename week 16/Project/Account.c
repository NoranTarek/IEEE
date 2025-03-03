#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Types.h"
#include "Account.h"
#include "include.h"

User *Uhead = NULL;
User *HelpAdd = NULL;
User *HelpView = NULL;
User *HelpDelete = NULL;
User *HelpHelpDelete = NULL;
User *HelpSearching = NULL;
User *HelpProcessing = NULL;
User *HelpHelpProcessing = NULL;

void User_Account_Management()
{
    printf("1-Create Account.     2-View Accounts.     3-Delete Account \n");
    u32 Uchoice;scanf("%d", &Uchoice);
    switch(Uchoice)
    {
    case 1:
        create_account();
        break;
    case 2:
        view_accounts();
        break;
    case 3:
        delete_account();
        break;
    }
}
void create_account()
{
    User *NewNode = (User*)malloc(sizeof(User));
    if(NewNode == NULL)
        printf("NULL POINTER");
    else
    {
        if(Uhead == NULL)
            Uhead = NewNode;
        else
        {
            HelpAdd = Uhead;
            while(HelpAdd->next != NULL)
            {
                HelpAdd = HelpAdd->next;
            }
            HelpAdd->next = NewNode;
            NewNode->next = NULL;
        }
        printf("Enter your name : ");
        scanf("%s", &NewNode->name);
        printf("Enter you id : ");
        scanf("%d", &NewNode->id);
        printf("Enter your balance : ");
        scanf("%d", &NewNode->balance);
        FILE *file = fopen("User.csv", "a");
		if (file == NULL) {
			printf("           Error opening file.\n");
		}
        else
        {
            fprintf(file, "%s,%d,%d\n", NewNode->name , NewNode->id , NewNode->balance);
            fclose(file);
        }
    }
}
void view_accounts()
{
    FILE *file = fopen("User.csv", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
    }
    else
    {
        char line[200];
        while (fgets(line, sizeof(line), file)) {
        User *newUser = (User*)malloc(sizeof(User));
        if (newUser == NULL) {
            printf("Memory allocation failed.\n");
        }
        else
        {
            sscanf(line, "%99[^,],%d,%d\n", newUser->name, &newUser->id, &newUser->balance);
            newUser->next = Uhead;
            Uhead = newUser;
        }
    }
    fclose(file);
    }
    u32 id , flag = 0;
    HelpView = Uhead;
    printf("Enter your id : ");
    scanf("%d", &id);
    while(HelpView != NULL)
    {
        if(HelpView->id == id)
        {
            flag = 1;
            break;
        }
        HelpView = HelpView->next;
    }
    if(flag == 0)
    {
        printf("Invalid id !");
    }
    else
    {
        printf("Your name : %s \nYour id : %d\nYour balance : %d\n",HelpView->name ,HelpView->id ,HelpView->balance);
    }
}
void delete_account()
{
    u32 id , flag = 0;
    HelpDelete = Uhead;
    printf("Enter your id : ");
    scanf("%d", &id);
    if(id == Uhead->id)
    {
        if(Uhead-> next == NULL)
        {
            free(Uhead);
            Uhead = NULL;
        }
        else
        {
            HelpDelete = Uhead;
            Uhead = Uhead->next;
            free(HelpDelete);
        }
    }
    else
    {
        while(HelpDelete != NULL)
        {
            if(HelpDelete->id == id)
            {
                flag = 1;
                break;
            }
            HelpHelpDelete = HelpDelete;
            HelpDelete = HelpDelete->next;
        }
        if(flag == 0)
        {
            printf("Invalid id !");
        }
        else
        {
            HelpHelpDelete->next = HelpDelete->next;
            free(HelpDelete);
        }
    }
}
int AccountSearching(char name[100])
{
    HelpSearching = Uhead;
    while(HelpSearching != NULL)
    {
        if(!strcmp(HelpSearching->name,name))
            return 1;
        HelpSearching = HelpSearching->next;
    }
    return 0;
}
void ProcessingTransaction(char sender[100],char receiver[100],int amount)
{
    HelpProcessing = Uhead;
    while(strcmp(HelpProcessing->name,sender))
        HelpProcessing = HelpProcessing->next;
    HelpProcessing->balance = HelpProcessing->balance - amount;
    HelpHelpProcessing = Uhead;
    while(strcmp(HelpHelpProcessing->name,receiver))
        HelpHelpProcessing = HelpHelpProcessing->next;
    HelpHelpProcessing->balance = HelpHelpProcessing->balance + amount;
    FILE *file = fopen("User.csv", "a");
    if (file == NULL) {
        printf("           Error opening file.\n");
    }
    else
    {
        fprintf(file, "%s,%d,%d\n", HelpProcessing->name , HelpProcessing->id , HelpProcessing->balance);
        fclose(file);
    }
    FILE *file2 = fopen("User.csv", "a");
    if (file2 == NULL) {
        printf("           Error opening file.\n");
    }
    else
    {
        fprintf(file2, "%s,%d,%d\n", HelpHelpProcessing->name , HelpHelpProcessing->id , HelpHelpProcessing->balance);
        fclose(file2);
    }
}
