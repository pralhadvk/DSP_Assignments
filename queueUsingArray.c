#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Queue
{
    int front,rear,size;
    int *arr;
};

void enqueue(struct Queue *q, int number)
{
    if(q->rear == q->size-1)
        printf("Queue is Full!!\n");
    else
        q->arr[++(q->rear)] = number; 
}

void dequeue(struct Queue *q)
{
    if(q->rear == q->front)
        printf("Queue empty!!\n");
    else
        printf("number dequeued is: %d\n",q->arr[++(q->front)]);
}

void display(struct Queue *q)
{
    printf("Elements in queue are as below:\n");
    for(int i=q->front+1;i<=q->rear;i++)
        printf(" %d ",q->arr[i]);
    printf("\n");
}

int main()
{
    int number,choice,N;
    bool noexit = true;
    printf("Enter size of array\n");
    scanf("%d",&N);

    struct Queue *q;
    q->front = q->rear = -1;
    q->size = N;
    q->arr = (int *)malloc(q->size*sizeof(int));

    while(noexit)
    {
        printf("Select the option for its corresponding action\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("Enter number to enqueue\n");
                    scanf("%d",&number);
                    enqueue(q,number);
        }
        else if(choice == 2)
        {
            dequeue(q);
        }
        else if(choice == 3)
        {
            display(q);
            printf("\n");
        }
        else if(choice == 4)
            noexit = false;
        
        else
            printf("Select the correct choice\n");
        
    }
}
