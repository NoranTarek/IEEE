#include <stdio.h>
#include <stdlib.h>
#include "Types.h"
#include "management.h"
u32 System_Init()
{
    FILE *file = fopen("User.csv", "r");
    if (file == NULL) {
        return 0;
    }
    else
    {
        fclose(file);
    }
    FILE *file1 = fopen("Transactions.csv", "r");
    if (file1 == NULL) {
        return 0;
    }
    else
    {
        fclose(file1);
    }
    return 1;
}
u32 main()
{
    u32 flag = System_Init();
    if(flag = 1)
    {
        printf("                     welcome   \n");
        u32 choice;
        while(1)
        {
            printf("1-User Account Management.      2- Transactions  \n");
            scanf("%d", &choice);
            switch(choice)
            {
            case 1:
                User_Account_Management();
                break;
            case 2:
                Trasactions();
                break;
            }
            printf("if you need another request press any key except 0\n");
            u32 nexit;scanf("%d", &nexit);
            if(nexit == 0)
                break;
        }
    }
    else
        printf("           Error opening file.\n");
    return 0;
}
