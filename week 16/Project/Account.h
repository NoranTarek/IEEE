#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

void User_Account_Management();
void create_account();
int AccountSearching(char name[100]);
void ProcessingTransaction(char sender[100],char receiver[100],int amount);

#endif // ACCOUNT_H_INCLUDED
