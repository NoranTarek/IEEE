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

struct node
{
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
            printf("1-first node.\n2-beginning. \n3-certain position.\n4-end.\n");
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
    printf("enter the data : \n");
    int data; scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    size++;
}

void beg_insertion()
{
      struct node *ptr = malloc(sizeof(struct node));
      if(ptr == NULL)
      {
          printf("NULL Pointer\n");
      }
      else
      {
          printf("enter the data : \n");
          int data; scanf("%d", &data);
          ptr->data = data;
          ptr->next = head;
          head = ptr;
          size++;
      }
}

void pos_insertion()
{
    struct node *ptr = malloc(sizeof(struct node));
      if(ptr == NULL)
      {
          printf("NULL Pointer\n");
      }
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
              hptr->next = ptr;
              size++;
          }
      }
}

void end_insertion()
{
    struct node *ptr = malloc(sizeof(struct node));
      if(ptr == NULL)
      {
          printf("NULL Pointer\n");
      }
      else
      {
          printf("enter the data : \n");
          int data; scanf("%d", &data);
          ptr->data = data;
          ptr->next = NULL;
          struct node *hptr = head;
          while(hptr->next != NULL)
          {
              hptr = hptr->next;
          }
          hptr->next = ptr;
          size++;
      }
}

void beg_deletion()
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    size--;
}

void pos_deletion()
{
    printf("enter the position : \n");
    int pos; scanf("%d", &pos);
    if(pos == 1)
    {
        beg_deletion();
    }
    else
    {
        struct node *ptr = head;
        while(--pos != 1)
        {
          ptr = ptr->next;
        }
        struct node *hptr = ptr->next;
        ptr->next = hptr->next;
        free(hptr);
        size--;
    }
}

void end_deletion()
{
    struct node *ptr = head;
    struct node *hptr = head;
    while(ptr->next != NULL)
    {
        hptr = ptr;
        ptr = ptr->next;
    }
    hptr->next = NULL;
    free(ptr);
    size--;
}

void list_deletion()
{
    struct node *ptr = head;
    while(--size != 0)
    {
        ptr = ptr->next;
        free(head);
        head = ptr;
    }
}

void printingList()
{
    struct node *ptr = head;
    while(ptr)
    {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void reverseList()
{
    struct node *ptr1 = NULL;
    struct node *ptr2 = NULL;
    while(head != NULL)
    {
        ptr2 = head->next;
        head->next = ptr1;
        ptr1 = head;
        head = ptr2;
    }
    head = ptr1;
}

void get_size()
{
    printf("%d \n",size);
}
