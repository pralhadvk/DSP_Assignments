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
        if(front == NULL)                      
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
    if(front == NULL)
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
    bool noexit = true;

    while(noexit)
    {
        printf("Select the option for its corresponding action\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("Enter number to enqueue\n");
            scanf("%d",&number);
            enqueue(number);
        }
        else if(choice == 2)
        {
            dequeue();
        }
        else if(choice == 3)
        {
            display();
            printf("\n");
        }
        else if(choice == 4)
            noexit = false;
        
        else
            printf("Select the correct choice\n");
    }
}
