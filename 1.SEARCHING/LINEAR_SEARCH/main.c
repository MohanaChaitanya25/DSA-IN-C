/// I.SEARCHING ///

// 1.LINEAR SEARCH //

#include <stdio.h>
int main()
{
    int n,se,i,f=0;
    printf("Enter No. of Elements & Search Element\n");
    scanf("%d %d",&n,&se);
    
    int a[n];
    printf("\nEnter %d Elements\n",n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(i=0; i<n; i++)
    {
        if(se == a[i])
        {
            printf("\nThe Search Element is found at the index : %d\n",i+1);
            f++;
            break;
        }
    }
    
    if(f==0)
        printf("\nThe Search Element is not present in the List\n");
    return 0;
}
