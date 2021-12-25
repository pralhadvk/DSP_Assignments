#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#define size 24
#define queueno 4

int k = size/queueno;
int queue[size];
int front[queueno];
int rear[queueno];
int count[queueno];
int current;

void initializeFrontRear()          //initializes front and rear indexes for every queue
{
    for(int i=0; i< queueno; i++)
        {
            rear[i] = k*i;
            front[i] = k*i;
        }
}

void display()              //displays every queue from front to rear
{
    printf("\nfour Queues are as follows:\n");
    int j = 0;
    while(j<queueno)
    {
        printf("Queue No %d:",j+1);
        
        for(int i = front[j]; i < rear[j]; i++)
            printf(" %d ",queue[i]);
        printf("\n");
        j++;
    }
    printf("\n");
}

void insertQueueNumber(int q, int data)   //inserts data into queue number pointed by q
{
    if(count[q]==k)
        printf("Queue Full!!\n");
    else
    {
        count[q]++;
        queue[rear[q]++] = data;
        // display();
    }
}
void enqueue(int value)                  //selects queue with minimum number and enqueues data into it
{   
    int queueIndex = -1, currCount = k;
    for(int i=0; i<queueno; i++)
        {
            if(count[i] < currCount)
                {
                    currCount = count[i];
                    queueIndex = i;
                }
        }
    if(-1 == queueIndex)
    {
        printf("Queue is full!!\n");
    }
    else
    {
        count[queueIndex]++;
        queue[rear[queueIndex]++] = value;
    }
}

void delete()               //finds queue with minimum number and dequeues data from it
{
    int queueIndex = -1, currCount = 0;
    for(int i=0; i<queueno; i++)
    {
        if(count[i] > currCount)
        {
            currCount = count[i];
            queueIndex = i;
        }
    }
    if(-1 == queueIndex)
    {
        printf("Queue is Empty!!\n");
        initializeFrontRear();
    }
    else
    {
        count[queueIndex]--;
        printf("Deleted number is: %d\n",queue[front[queueIndex]]);
        queue[front[queueIndex]] = 0;
        front[queueIndex]++;
    }
}

void initializeQueues()             //fills data as per the initial conditions
{
    for(int i=11; i<=15; i++)
        insertQueueNumber(0,i);
    for(int i=21; i<=23; i++)
        insertQueueNumber(1,i);
    for(int i=31; i<=32; i++)
        insertQueueNumber(2,i);
    for(int i=41; i<=46; i++)
        insertQueueNumber(3,i);
}

void main()
{   
    int choice, data;
    bool exit = false;
    initializeFrontRear();
    initializeQueues();
    display();
    while(!exit)
    {   
        printf("Select choice from below\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        if(!scanf("%d",&choice))
            {
                printf("Program exit due to alphabet entered!!\n");
                break;
            }
        if(1 == choice)
        {
            printf("Enter number to insert\n");
            scanf("%d", &data);
            enqueue(data);
            display();
        }
        else if(2 == choice)
        {
            delete();
            display();
        }
        else if(3 == choice)
        {
            display();
        }
        else if(4 == choice)
        {
            break;
        }
        else
        {
            printf("INVALID INPUT\n");
        }
    }
}

