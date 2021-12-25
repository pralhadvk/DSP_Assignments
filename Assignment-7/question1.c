#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"quickSort1.h"    //for type 1
#include"quickSort2.h"    //for type 2
#include"quickSort3.h"    //for type 3
#include"quickSort4.h"    //for type 4
#define SIZE 1000000        //needs to change for varing the number of inputs

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
void main()
{    
  clock_t start_time, end_time;
  double cpu_time_used;
  
  printf("---------- For Size %d ------------\nPivotType  Random  Sorted  AlmostSorted\n",SIZE);
  for(int j=1; j<=4; j++)
  { 
    printf("Type-%d",j);
    for(int k=1; k<=3; k++)
    {
      srand(time(NULL));
      if(1==k)
        initializeRandom();
      else if(2 == k)
        initializeSorted();
      else
        initializeAlmostSorted();
      if(1 == j)
      {
        start_time = clock();
        quickSort1(arr,0,SIZE-1);
        end_time = clock();
      }
      else if(2 == j)
      {
         start_time = clock();
         quickSort2(arr,0,SIZE-1);
         end_time = clock();
      }
      else if(3 == j)
      {
        start_time = clock();
        quickSort3(arr,0,SIZE-1);
        end_time = clock();
      }
      else if(4 == j)
      {
        start_time = clock();
        quickSort4(arr,0,SIZE-1);
        end_time = clock();
      }
      cpu_time_used = ((double)(end_time-start_time))/CLOCKS_PER_SEC;
      printf(" %f",cpu_time_used);
    }
    printf("\n");
  }
}
