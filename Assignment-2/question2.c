#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void insert(int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p;
    temp->data = value;
    temp->next = NULL;
    if(!head)
    {
        head = temp;
    }
    else
    {
        p = head;
        while(p->next)
            p = p->next;
        p->next = temp;
    }
}

void display()
{
    struct Node *p;
    p=head;
    if(!head)
        printf("List is Empty!!\n");
    else
    {
        while(p)
            {
                printf(" %d->",p->data);
                p = p->next;
            }
        printf("NULL\n");
    }
    
}

void calculateValue()
{
    struct Node *p = head;
    int ans = 1;
    while(!p->data)             // use to skip preceeding 0
        p=p->next;
    p=p->next;                  //holds pointer to first 1 in string
    while(p)
    {
        ans = ans*2+(p->data);
        p=p->next;
    }
    printf("Decimal Value is: %d\n",ans);
}

void main()
{
    bool exit = false;
    int choice,value;
    printf("Select the options for its actions\n1. Insert\n2. Print Value\n3. Display\n4. Quit\n");
    scanf("%d",&choice);
    while(!exit)
    {
        if(choice == 1)
            {
                printf("Enter Value to enter in decimal\n");
                scanf("%d",&value);
                while(value != 0 && value != 1)
                    {
                       printf("Enter Value to enter in decimal\n");
                       scanf("%d",&value); 
                    }
                insert(value);
            }
        else if(choice == 2)
                calculateValue();
        else if(choice == 3)
                display();
        else if(choice == 4)
                break;
        else
            printf("Invalid Choice!!");
        
        printf("Select the options for its actions\n1. Insert\n2. Print Value\n3. Display\n4. Quit\n");
        scanf("%d",&choice);
    }
}