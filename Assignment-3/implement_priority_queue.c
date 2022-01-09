#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define capacity 100                 //change for increasing size of array structure 

struct student
{
    int gateScore;
    char name[100];
};

struct student st[capacity];        //array of structure containing int and array in it
int size = -1;

void enqueue(char name[], int score)
{   
    int i=0;
    size++;
    if(size == capacity)
        printf("Queue Full!!\n");
    else
    {
        while(st[size].name[i] = name[i])
            i++;
        st[size].gateScore = score;

        printf("Current Student list is:\n");
        for(int i=0;i<=size; i++)
            printf("%d: name: %s\tscore:%d\n",i,st[i].name,st[i].gateScore);
    }
}

int peek()
{
    int index = -1;
    int highestScore = st[0].gateScore;
    for(int i=0; i<=size; i++)
        {
            if(st[i].gateScore > highestScore)
            {
                highestScore = st[i].gateScore;
                index = i;
            }
        } 
    if(-1 == index && 0 <= size)
        return 0;
    else
        return index;
}

void dequeue()
{   
    if(-1 == size)
        printf("No Student Data present!!\n");
    else
    {
        int loc = peek();
        printf("Student Selected for removal is:\nname: %s\ngateScore: %d\n",st[loc].name,st[loc].gateScore);

        for(int i=loc; i<size; i++)
            st[i] = st[i+1];
        size--;
        printf("Current Student list is:\n");
        for(int i=0;i<=size; i++)
            printf("%d: name: %s\tscore:%d\n",i,st[i].name,st[i].gateScore);
    }
}

bool isChar(char ch)            //checks whether name entered is valid or not, valid name starts with characters
{
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return true;
    return false;
}

void main()
{   
    int choice,score;
    char name[100];
    while(1)
    {
        printf("select the below choice:\n1.insert\n2.delete\n3.exit\n");
        if(!scanf("%d",&choice))
            {
                printf("Program exit due to non-numeric input\n");
                break;
            }
        if(1 == choice)
        {
            printf("Enter name:\n");
            scanf("%s",name);
            char firstChar = name[0];
            if(!isChar(firstChar))
            {
                printf("Entered name is invalid!\n");
                break;
            }    
            printf("Enter gate Score\n");
            if(!scanf("%d",&score))
            {
                printf("Program exit due to non-numeric input\n");
                break;
            }
            enqueue(name,score);
        }
        else if(2 == choice)
            dequeue();
        else if(3 == choice)
            break;
        else
            printf("Invalid Choice!!\n");

    }
}
