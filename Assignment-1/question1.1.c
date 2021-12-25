#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int arr[10], top=-1;

void push(int number)
{
    if(top == 9)
        printf("Stack full!!\n");
    else
        arr[++top] = number;
}

void pop()
{
    if(top == -1)
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
    bool noexit = true;
    printf("Size of stack is 10 Elements\n");

    while(noexit)
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
            noexit = false;
        }
        else
            printf("Select the correct choice\n");
        
    }
}
