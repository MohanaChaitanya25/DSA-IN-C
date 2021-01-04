/// II.SORTING ///

// 3.SELECTION SORT //

#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
} 

void SelectionSort(int a[], int n)
{
    int i,j,min_index;
    for(i=0; i<n; i++)
    {
        min_index = i;
        for(j=i+1; j<n; j++)
        {
            if(a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        if(min_index != i)
        {
            swap(&a[i],&a[min_index]);
        }
    }
}

void print_array(int a[], int n)
{
    printf("\nSorted List by Seletion Sort : ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    int i,n;
    printf("Enter No. of Elements\n");
    scanf("%d",&n);
    
    int a[n];
    printf("\nEnter %d Elements\n",n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    SelectionSort(a,n);
    print_array(a,n);
    return 0;
}
