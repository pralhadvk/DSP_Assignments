#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
{   
    int N,k,i=0,j=0,test,sum=0,minSubarray,size=0,temp,start,end;
    printf("Enter the number of terms\n");
    scanf("%d",&N);
    int minSize = N;
    int arr[N];
    printf("Enter %d terms:\n",N);
    for(int i=0; i<N; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the term of sum\n");
    scanf("%d",&k);
    for(int i=0; i<N;i++)
    {
        sum = arr[i];
        size = 1;
        if(sum > k)
            {
                start=i;
                end=j;
                size = 1;
                break;
            }
        for(int j=i+1; j<N; j++)
        {   
            size++;
            if((sum+arr[j]>k) && size<minSize)
            {
                minSize = size;
                start = i;
                end = j;
                break;
            }
            sum += arr[j];
        }
    }
    
	printf("Maximum Subarray is for the minSize: %d\n",minSize);
	for(int i= start; i<=end; i++)
	{
	    printf(" %d ",arr[i]+minSize);
	}
    //printf("minLength: %d start: %d end:%d",minSize,start,end);
}
