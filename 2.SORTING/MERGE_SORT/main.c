/// II.SORTING ///

// 5.MERGE SORT //

#include <stdio.h>

void Merge(int a[],int beg,int mid,int end)
{
    int i=beg, j=mid+1, index=beg, b[beg+end+1], k;
    while(i<=mid && j<=end)
    {
        if(a[i] < a[j])
        {
        b[index] = a[i];
        i++;
        }
            else
            {
                b[index] = a[j];
                j++;
            }
        index++;
    }
    if(i>mid)
    {
        while(j<=end)
        {
            b[index] = a[j];
            j++;
            index++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[index] = a[i];
            i++;
            index++;
        }
    }
    for(k=beg;k<index;k++)
    a[k] = b[k];
}

void MergeSort(int a[],int beg,int end)
{
    if(beg<end)
    {
       int mid = (beg+end)/2;
       MergeSort(a,beg,mid);
       MergeSort(a,mid+1,end);
       Merge(a,beg,mid,end);
    }
}

void print_array(int a[],int n)
{
    printf("\nSorted List by Merge Sort : ");
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
    
    int a[n];
    printf("\nEnter %d Elements\n",n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    
    MergeSort(a,0,n-1);
    print_array(a,n);
    return 0;
}
