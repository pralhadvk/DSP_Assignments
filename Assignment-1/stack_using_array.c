#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int arr[10], top=-1;

void push(int number)
{
    if(9 == top)
        printf("Stack full!!\n");
    else
        arr[++top] = number;
}

void pop()
{
    if(-1 == top)
        printf("Stack is empty!!\n");
    else
        arr[top--] = 0;
}

void display()
{
    int i=0;
    printf("Current stack is\n");
    while(arr[i] && i<10)
    {
        printf(" %d ",arr[i]);
        i++;
    }
}

int main()
{
    int number,choice;
    bool exit = false;
    printf("Size of stack is 10 Elements\n");

    while(!exit)
    {
        printf("Select the option for its corresponding action\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d",&choice);
        if(1 == choice)
        {
            printf("Enter number except 0 to push\n");
            scanf("%d",&number);
            push(number);
        }
        else if(2 == choice)
        {
            pop();
        }
        else if(3 == choice)
        {
            display();
            printf("\n");
        }
        else if(4 == choice)
        {
            exit = true;
        }
        else
            printf("Select the correct choice\n");
        
    }
}
