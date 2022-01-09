#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <limits.h>
#include<stdbool.h> 

struct Stack
{
    int top,size;
    int *arr;
};

struct Stack *createStack(int disks)
{
    struct Stack *st =(struct Stack *)malloc(sizeof(struct Stack));
    st-> top = -1;
    st->size = disks;
    st->arr = (int *)malloc(disks*sizeof(int));
    return st;
}
bool isFull(struct Stack *st)
{
    if(st->top==st->size-1)
        return true;
    else
        return false;
}

bool isEmpty(struct Stack *st)
{
    if(st->top == -1)
        return true;
    else
        return false;
}

int pop(struct Stack *st)
{
    if(!isEmpty(st))
        return st->arr[st->top--];          //returns stack top and then decrements top value
    else
        return INT_MIN;
}

void push(struct Stack *st, int number)
{
    if(isFull(st))
        return;
    else
        st->arr[++st->top] = number;        //preincrements stack top and then assigns value at that position
}

void printDiskMoves(char from, char to, int diskNo)
{
    printf("Move Disk no %d from tower %c to tower %c\n",diskNo,from,to);
}
void moveDisk(struct Stack *src, struct Stack *dest, char s, char d)    //actually moves the stack array number
{
    int stackTop1 = pop(src);
    int stackTop2 = pop(dest);
    if(stackTop1 == INT_MIN)           //stack 1 i.e. source is empty hence push stacktop2 onto stacktop1
    {
        push(src,stackTop2);
        printDiskMoves(d,s,stackTop2);
    }
    else if(stackTop2 == INT_MIN)       //stack 2  i.e. dest is empty hence push stacktop1 onto stacktop2
    {
        push(dest,stackTop1);;
        printDiskMoves(s,d,stackTop1);
    }
    else if(stackTop1 > stackTop2)      //number on dest is less than number on src hence push src disk to dest
    {
        push(src,stackTop1);
        push(src,stackTop2);
        printDiskMoves(d,s,stackTop2);
    }
    else                                //number in src is less than number on dest hence push srd on dest
    {
        push(dest,stackTop2);
        push(dest,stackTop1);
        printDiskMoves(s,d,stackTop1);
    }
}
void TOH(int noOfDisk, struct Stack *sr,struct Stack *dt, struct Stack *ax)
{
    int totalMoves = pow(2, noOfDisk) -1;               //obtained from recursive formula
    char source = 'S', destination ='D', auxiliary = 'A';
    if(noOfDisk%2 == 0)                     // through observation
    {
		char temp = destination;
		destination = auxiliary;
		auxiliary = temp;
	}

    for(int i=noOfDisk; i>=1; i--)          //initial push on src stack
        push(sr,i);

    for(int i=1; i<=totalMoves;i++)
    {
        if(i%3 == 1)
            moveDisk(sr,dt,source,destination);
        else if(i%3 == 2)
            moveDisk(sr,ax,source,auxiliary);
        else if(i%3 == 0)
            moveDisk(ax,dt,auxiliary,destination);
    }
}
void main()
{
    int noOfDisk;
    printf("Enter no of Disk\n");
    scanf("%d",&noOfDisk);

    struct Stack *sr, *dt, *ax;
    sr = createStack(noOfDisk);         //array of size equals no of disks
    dt = createStack(noOfDisk);         //array of size equals no of disks
    ax = createStack(noOfDisk);         //array of size equals no of disks

    TOH(noOfDisk,sr,dt,ax);

}
