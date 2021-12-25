
void median(int *arr, int low, int mid, int high)
{
    if((arr[low] <= arr[mid] <= arr[high]) || (arr[high] <= arr[mid] <= arr[low]))
        swap(&arr[mid], &arr[low]);
    else if((arr[mid] <= arr[low] <= arr[high]) || (arr[high] <= arr[low] <= arr[mid]))
        swap(&arr[low],&arr[low]);
    else if((arr[low] <= arr[high] <= arr[mid]) || (arr[mid] <= arr[high] <= arr[low]))
        swap(&arr[high],&arr[low]);
}
int partition3(int arr[],int low,int high)
{   
    int pivot,mid,temp;
    if((high-low+1)>=3)
    {
        mid = (low+high)/2;
        median(arr,low,mid,high);
        
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
void quickSort3(int arr[], int low, int high)
{   
    int pivot;
    if(low < high)
    {
        pivot = partition3(arr,low,high);
        quickSort3(arr,low,pivot-1);
        quickSort3(arr,pivot+1,high);
    }

}

