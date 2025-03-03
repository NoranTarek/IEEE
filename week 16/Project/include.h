#ifndef INCLUDE_H_INCLUDED
#define INCLUDE_H_INCLUDED

#define MAX_LENGTH 100
typedef struct transaction
{
    u8 sender[MAX_LENGTH];
    u8 receiver [MAX_LENGTH];
    u32 amount;
    struct transaction *next;
}Transaction;

typedef struct user
{
    u8 name[MAX_LENGTH];
    u32 id;
    u32 balance;
    struct user *next;
}User;


#endif // INCLUDE_H_INCLUDED
