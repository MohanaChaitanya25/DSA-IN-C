/// II.SORTING ///

// 2.INSERSION SORT //

#include <stdio.h>
void InsertionSort(int a[], int n)
{
    int i,j,temp;
    for(i=1; i<n; i++)
    {
        temp = a[i];
        j = i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

void print_array(int a[], int n)
{
    printf("\nSorted List by Insertion Sort : ");
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
    InsertionSort(a,n);
    print_array(a,n);
    return 0;
}