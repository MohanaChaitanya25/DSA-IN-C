/// II.SORTING ///

// 1.BUBBLE SORT //

#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int a[], int n)
{
    int i,j,flag;
    for(i=0; i<n-1; i++)
    {
        flag = 0;
        for(j=0; j<n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(&a[j],&a[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            break;
        }
    }
}

void print_array(int a[], int n)
{
    printf("\nSorted List by Bubble Sort : ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    int n,i;
    printf("Enter No. of Elements\n");
    scanf("%d",&n);
    
    int a[n];
    printf("\nEnter %d Elements\n",n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    BubbleSort(a,n);
    print_array(a,n);
    return 0;
}
