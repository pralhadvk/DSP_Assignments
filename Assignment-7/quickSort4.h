int partition4(int arr[],int low,int high)
{   
    int pivot,mid;
    if((high-low+1)>=4)
    {   
        mid = (low+high)/2;
        median(arr,low,mid,high-1);
    }
    
    pivot = arr[low];
    int i = (high+1);
    for(int j=high; j>=low+1; j--)
    {
        if(arr[j]>pivot)
        {
            swap(&arr[--i],&arr[j]);
        }
    }
    swap(&arr[i-1],&arr[low]);
    return (i-1);

}
void quickSort4(int arr[], int low, int high)
{   
    int pivot;
    if(low < high)
    {
        pivot = partition4(arr,low,high);
        quickSort4(arr,low,pivot-1);
        quickSort4(arr,pivot+1,high);
    }

}

