#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 1000000         //default size 

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int arr[SIZE];
int n, choice;

void heapify(int *arr, int n)
{
    if(choice == 1)
    {
         int j;
        for(int i=(n/2)-1; i >= 0; i--)
        {
            j = 2*i + 1;
            while(j<n-1)
            {
                if(arr[j]<arr[j+1])
                    j=j+1;

                if(arr[i]<arr[j])
                {
                    swap(&arr[i],&arr[j]);
                    i = j;
                    j = 2*i +1;
                }
                else
                    break;
            }
            if(j==n-1 && arr[j]>arr[i])
                swap(&arr[i],&arr[j]);
        }
    }
    else
    {
     
        int j;
        for(int i=(n/2)-1; i >= 0; i--)
        {
            j = 2*i + 1;
            while(j<n-1)
            {
                if(arr[j]>arr[j+1])
                    j=j+1;

                if(arr[i]>arr[j])
                {
                    swap(&arr[i],&arr[j]);
                    i = j;
                    j = 2*i +1;
                }
                else
                    break;
            }
            if(j==n-1 && arr[j]<arr[i])
                swap(&arr[i],&arr[j]);
        }
    }
}

int delete()
{   
    heapify(arr,n);
    int x = arr[0];
    arr[0] = arr[n-1];
    n--;
    return x;
}

void sort()
{
   int x = n;
   while(x>=2)
   {
       heapify(arr,x);
       swap(&arr[0], &arr[x-1]);
       x--;
   }
}

bool isPresent(int value)           //used to check for duplicate values
{
    for(int i=0; i<n; i++)
        if(arr[i] == value)
            return true;
    return false;
}
int main()
{
    int x,temp;
    bool exit = false;
    printf("Enter 1 for Max-Heap 2 for Min-Heap\n");
    scanf("%d",&choice);
    while(choice < 1 || choice > 2)
        {
            printf("Enter valid choice!\n");
            scanf("%d",&choice);
        }
    printf("Enter number of elements for Build heap\n");
    scanf("%d", &n);
    if(n > SIZE)
    {
        printf("value of n is greater than max defined for it\n");
        return 1;
    }
    printf("Enter %d numbers\n",n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &temp);
        if(isPresent(temp))
        {
            printf("Duplicate values not allowed!\n");
            return 1;
        }
        arr[i] = temp;
    }
    heapify(arr,n);
    while(!exit)
    {
        printf("Select the following options:\n1.Insert Key\n2.Delete\n3.sort\n4.Exit\n");
        scanf("%d",&x);
        if(x==1)
        {
            printf("Enter key to insert\n");
            scanf("%d",&temp);
            if(isPresent(temp))
            {
                printf("Duplicate values not allowed!\n");
                return 1;
            }
            arr[n] = temp;
            n++;
            heapify(arr,n);
        }
        else if(x==2)
        {   
            if(n > 0)
            {
                printf("Deleted element is: %d\n", delete());
            }
            else
                printf("Heap Empty!\n");
        }
        else if(x==3)
        {
            sort();
            printf("After sort\n");
            for(int i=0; i<n; i++)
                printf(" %d ", arr[i]);
            printf("\n");
        }
        else if(x==4)
            exit = true;
        else
        {
            printf("Invalid choice\n");
            continue;
        }
    }
}
