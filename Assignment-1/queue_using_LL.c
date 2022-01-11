#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front;         //initialized to NULL
struct Node *rear;          //initialized to NULL

void enqueue(int number)
{
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    if(!temp)
        printf("Queue Full!!\n");
    else
    {     
        temp->data = number;
        temp->next = NULL;
        if(NULL == front)                      
            front = rear = temp;        //if queue is initially empty set front and rear to new node
        else
        {
            rear->next = temp;
            rear = temp;                //rear pointer is made to new node
        }
    }
}

void dequeue()
{
    struct Node *temp;
    if(NULL == front)
        printf("Queue is Empty!!\n");
    else
    {
        temp = front;
        printf("Dequeued value is: %d\n",front->data);
        front = front->next;                        //front pointer is set to next node
    }
}

void display()
{
    printf("Elements in queue are as below:\n");
    struct Node *temp;
    temp = front;
    while(temp)                             //itearte through all the LL
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int number,choice;
    bool exit = false;

    while(exit)
    {
        printf("Select the option for its corresponding action\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d",&choice);
        if(1 == choice)
        {
            printf("Enter number to enqueue\n");
            scanf("%d",&number);
            enqueue(number);
        }
        else if(2 == choice)
        {
            dequeue();
        }
        else if(3 == choice)
        {
            display();
            printf("\n");
        }
        else if(4 == choice)
            exit = true;
        
        else
            printf("Select the correct choice\n");
    }
}
