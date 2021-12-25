void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

int partition1(int arr[],int low,int high)
{
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
void quickSort1(int arr[], int low, int high)
{   
    int pivot;
    if(low < high)
    {
        pivot = partition1(arr,low,high);
        quickSort1(arr,low,pivot-1);
        quickSort1(arr,pivot+1,high);
    }

}
