#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
    {
        int data;
        struct Node* next;
    };

    struct Node* top = NULL;

struct Node* createNewNode(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void push(int number)
{
    if(top == NULL)
        top = createNewNode(number);
    else
    {
        struct Node* temp = createNewNode(number);
        temp->next = top;
        top = temp;
        printf("Number at top is: %d\n",top->data);
    }
}

void pop()
{
    if(top == NULL)
        printf("Stack Empty!!\n");
    else
    {
        struct Node* temp = top;
        top = top->next;
        printf("Number popped is: %d\n",temp->data);
        free(temp);
    }

}

void display()
{
    if(top == NULL)
        printf("Stack is Empty!!\n");
    else
    {
        struct Node* temp = top;
        while(temp)
        {
            printf(" %d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    bool exit = false;
    int choice,number;
    while(!exit)
    {
        printf("Select the option for its corresponding action\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("Enter number except 0 to push\n");
            scanf("%d",&number);
            push(number);
        }
        else if(choice == 2)
        {
            pop();
        }
        else if(choice == 3)
        {
            display();
            printf("\n");
        }
        else if(choice == 4)
        {
            exit = true;
        }
        else
            printf("Select the correct choice\n");
        
    }
}