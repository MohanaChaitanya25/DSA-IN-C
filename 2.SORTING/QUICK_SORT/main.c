/// II.SORTING ///

// 4.QUICK SORT //

#include <stdio.h>

void swap(int *x, int *y)
{
    int temp =*x;
    *x = *y;
    *y = temp;
}

int Partition(int a[], int lb, int ub)
{
    int start = lb;
    int end = ub;
    int pivot = a[lb];
    
    while(start < end)
    {
        while(a[start] <= pivot)
        {
            start++;
        }
        while(a[end] > pivot)
        {
            end--;
        }
        if(start < end)
        {
            swap(&a[start],&a[end]);
        }
    }
    swap(&a[lb],&a[end]);
    return end;
}

void QuickSort(int a[], int lb, int ub)
{
    if(lb < ub)
    {
        int loc = Partition(a,lb,ub);
        QuickSort(a,lb,loc-1);
        QuickSort(a,loc+1,ub);
    }
}

void print_array(int a[],int n)
{
    printf("\nSorted List by Quick Sort : ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter No. of Elements\n");
    scanf("%d",&n);
    
    int a[n],lb=0,ub=n-1;
    printf("\nEnter %d Elements\n",n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    
    QuickSort(a,lb,ub);
    print_array(a,n);
    return 0;
}
