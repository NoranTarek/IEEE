#include <stdio.h>
#include <stdlib.h>

void FN_insertion();
void beg_insertion();
void pos_insertion();
void end_insertion();
void beg_deletion();
void pos_deletion();
void end_deletion();
void list_deletion();
void printingList();
void reverseList();
void get_size();
void creatingList();

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

int size = 0;
struct node *head = NULL;

int main()
{
    while(1)
    {
        printf("select the option : \n");
        printf("1-Insertion. \n2-Deletion.\n3-Traversing.\n" );
        int option;
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            printf("enter the position of insertion : \n");
            printf("1-first node.\n2-beginning. \n3-certain position.\n4-end.\n5-Creating list.\n");
            int Ipos;scanf("%d", &Ipos);
            switch(Ipos)
            {
            case 1:
                FN_insertion();
                break;
            case 2:
                beg_insertion();
                break;
            case 3:
                pos_insertion();
                break;
            case 4:
                end_insertion();
                break;
            case 5:
                creatingList();
                break;
            }
             break;
        case 2:
            if(size == 0)
                printf("empty list\n");
            else
            {
                printf("enter the position of deletion : \n");
                printf("1-beginning. \n2-certain position.\n3-end.\n4-deleting the list.\n");
                int Dpos;scanf("%d", &Dpos);
                switch(Dpos)
                {
                case 1:
                    beg_deletion();
                    break;
                case 2:
                    pos_deletion();
                    break;
                case 3:
                    end_deletion();
                    break;
                case 4:
                    list_deletion();
                    break;
                }
            }
            break;
        case 3:
            if(size == 0)
                printf("empty list\n");
            else
            {
                printf("select the process : \n");
                printf("1-printing the data. \n2-reverse the list.\n3-get size.\n");
                int Tpos;scanf("%d", &Tpos);
                switch(Tpos)
                {
                case 1:
                    printingList();
                    break;
                case 2:
                    reverseList();
                    break;
                case 3:
                    get_size();
                    break;
                }
            }
            break;
        }
        printf("1-EXIT. \n2-CONTINUE.\n");
        int check; scanf("%d", &check);
        if(check == 1)
            break;
    }
    return 0;
}

void FN_insertion()
{
    head = malloc(sizeof(struct node));
    head->next = NULL;
    head->prev = NULL;
    printf("enter the data : \n");
    int data;scanf("%d", &data);
    head->data = data;
    size++;
}

void beg_insertion()
{
    if(head == NULL)
        FN_insertion();
    else
    {
        struct node *ptr = malloc(sizeof(struct node));
        if(ptr == NULL)
            printf("null pointer \n");
        else
        {
            printf("enter the data : \n");
            int data;scanf("%d", &data);
            ptr->prev = NULL;
            ptr->data = data;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
    }
    size++;
}

void pos_insertion()
{
    struct node *ptr = malloc(sizeof(struct node));
    if(ptr == NULL)
        printf("null pointer \n");
    else
    {
        printf("enter the position : \n");
        int pos; scanf("%d", &pos);
        if(pos == 1)
        {
          beg_insertion();
        }
        else
        {
          printf("enter the data : \n");
          int data; scanf("%d", &data);
          ptr->data = data;
          struct node *hptr = head;
          pos--;
          while(pos-- != 1)
          {
              hptr = hptr->next;
          }
          ptr->next = hptr->next;
          ptr->prev = hptr;
          hptr->next = ptr;
        }
        size++;
    }
}

void end_insertion()
{
    struct node *ptr = malloc(sizeof(struct node));
        if(ptr == NULL)
            printf("null pointer \n");
        else
        {
            printf("enter the data : \n");
            int data;scanf("%d", &data);
            struct node *hptr = head;
            ptr->data = data;
            while(hptr->next != NULL)
                hptr = hptr->next;
            hptr->next = ptr;
            ptr->prev = hptr;
            ptr->next = NULL;
        }
    size++;
}

void creatingList()
{
    int n , data , i;
    printf("enter the number of nodes : \n");
    scanf("%d", &n);
    if(n == 0)
        printf("underflow\n");
    else
    {
        printf("enter the data of the first node : \n");
        FN_insertion();
        for(i = 1; i < n;i++)
        {
            printf("enter the data of the node %d : \n",i+1);
            end_insertion();
        }
        size = n;
    }
}

void beg_deletion()
{
    head = head->next;
    free(head->prev);
    size--;
}

void pos_deletion()
{
    printf("enter the position : \n");
    int pos; scanf("%d", &pos);
    if(pos == 1)
        beg_deletion();
    else
    {
        struct node *ptr = head;
        while(pos-- != 1)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
        size--;
    }
}
void end_deletion()
{
    struct node *ptr = head;
    while(ptr->next->next != NULL)
        ptr = ptr->next;
    free(ptr->next);
    ptr->next = NULL;
    size--;
}

void list_deletion()
{
    if(size == 1)
        beg_deletion();
    else
    {
        while(--size != 0)
        {
            head = head->next;
            free(head->prev);
        }
    }
}

void printingList()
{
    struct node *ptr = head;
    while(ptr != NULL)
    {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void reverseList()
{
    struct node *ptr1 = head;
    struct node *ptr2 = ptr1->next;
    ptr1->next = NULL;
    ptr1->prev = ptr2;
    while(ptr2 != NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;
}

void get_size()
{
    printf("%d\n",size);
}
