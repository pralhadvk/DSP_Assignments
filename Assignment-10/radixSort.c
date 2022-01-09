#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

struct node             
{
    int data;
    struct node *next;
};

struct node *dec[10];

void initializeDecArray()       //sets all pointer in dec array to NULL
{
    for(int i=0; i<10; i++)
        dec[i] = NULL;
}

void insertElements(int *arr, int n, int digits)    //inserts elements into dec array based on digits in units,then tens and so on
{
    int index;
    for(int i=0; i<n; i++)
    {
        index = (arr[i]/digits)%10;                 //digits increases by factor of 10 to get units, tens, hundred place digits
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->next = NULL;
        if(!dec[index])
            dec[index] = temp;
        else
        {   
            struct node *ptr = dec[index];
            while(ptr->next)
                ptr = ptr->next;
            ptr->next = temp;
        }
    }
}

void copyToArray(int *arr, int n)       //based on the elememts presents in different positions in dec array they are copied accordingly back to original array
{   
    int j = 0;
    for(int i=0; i<10; i++)
    {
        if(dec[i])
        {
            struct node *ptr = dec[i];
            while(ptr)
            {
                arr[j++] = ptr->data;
                ptr = ptr->next;
            }
        }
    }
    initializeDecArray();
}

void radixSort(int *arr, int elements, int digits)      //iteratively calls insert and copy function by increasing digit value by order of 10
{   
    for(int i=0; i<digits;i++)
    {
        insertElements(arr,elements,(int)(pow(10, i) + 1e-9));
        copyToArray(arr,elements);
    }
    printf("Sorted array is as follow:\n");
    for(int i=0; i<elements;i++)
        printf(" %d ", arr[i]);
    printf("\n");
}

int main()
{
    int elements,maxElement = INT_MIN,digits = 0;
    printf("Enter number of elements to sort\n");
    scanf("%d", &elements);
    int arr[elements];
    printf("Enter Elements to be sorted\n");
    for(int i=0; i<elements; i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i] > maxElement)
            maxElement = arr[i];
    }
    while(maxElement)
    {
        digits += 1;
        maxElement = maxElement/10;
    }
    radixSort(arr,elements,digits);   
}



