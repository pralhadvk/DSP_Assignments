#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#define SIZE 10000000     //change for different inputs

int i;
int arr[SIZE];

void initializeRandom()
{
  for(i=0;  i<SIZE; i++)
    arr[i] = rand()%SIZE;
}

void initializeSorted()
{
  for(i=0;  i<SIZE; i++)
    arr[i] = i+1;
}

void initializeAlmostSorted()
{
  for(i=0;  i<SIZE; i++)
    {
      if(i<(SIZE/100))                     
          {
              arr[i] = rand()%(SIZE/100);
              continue;
          }
          arr[i] = rand()%SIZE;
    }
}

void merge(int *Arr, int p,int q,int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    int *leftArray = (int *) malloc((n1+1)*sizeof(int));
    int *rightArray = (int *) malloc((n2+1)*sizeof(int));
    for(int i=0; i<n1; i++)
        leftArray[i] = Arr[p+i];
    
    for(int i=0; i<n2; i++)
        rightArray[i] = Arr[q+i+1];

    leftArray[n1] = INT_MAX;
    rightArray[n2] = INT_MAX;

    int i,j;
    i=j=0;
    for(int k=p; k<=r; k++)
       {
            if(leftArray[i] <= rightArray[j])
            {
                Arr[k] = leftArray[i];
                i++;
            }
            else
            {
                Arr[k] = rightArray[j];
                j++;
            }
       }
}

void mergeSort(int *Arr, int l, int r)
{
    int q;
    if(l<r)
    {
        q=(l+r)/2;
        mergeSort(Arr,l,q);
        mergeSort(Arr,q+1,r);
        merge(Arr,l,q,r);
    }
}
void main()
{   
    clock_t start_time, end_time;
    double cpu_time_used;
    printf("-------- For input %d ------------\n Random  Sorted  AlmostSorted\n",SIZE);
    for(int j=1; j<=3; j++)
    {   
        srand(time(NULL));
        if(1 == j)
            initializeRandom();
        else if(2 == j)
            initializeSorted();
        else
            initializeAlmostSorted();
        start_time = clock();
        mergeSort(arr,0,SIZE-1);
        end_time = clock();
        cpu_time_used = ((double)(end_time-start_time))/CLOCKS_PER_SEC;
        printf(" %f ",cpu_time_used);        
    }
    printf("\n");  
}
