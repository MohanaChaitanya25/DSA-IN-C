/// I.SEARCHING ///

// 2.BINARY SEARCH //

#include <stdio.h>

void BinarySearch(int a[], int n, int se)
{
    int l=0,r=n-1,mid;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(se == a[mid])
        {
            printf("\nThe Search Element is present at the index: %d\n",mid+1);
            break;
        }
        else if(se<a[mid])
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    
    if(l>r)
        printf("The Search Element is not Present in the List\n");
}


int main()
{
    int n,se,i;
    printf("Enter No. of Elements & Search Element\n");
    scanf("%d %d",&n,&se);
    
    int a[n];
    printf("\nEnter %d Elements\n",n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    
    BinarySearch(a,n,se);
    return 0;
}
