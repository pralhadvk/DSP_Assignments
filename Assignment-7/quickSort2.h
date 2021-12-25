int partition2(int arr[],int low,int high)
{
    int random = low + rand() % (high - low);
    swap(&arr[random],&arr[low]);
    int pivot = arr[low];
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
void quickSort2(int arr[], int low, int high)
{   
    int pivot;
    if(low < high)
    {
        pivot = partition2(arr,low,high);
        quickSort2(arr,low,pivot-1);
        quickSort2(arr,pivot+1,high);
    }

}

