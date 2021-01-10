#include <stdio.h>
#include <stdlib.h>
//Program for binary search
int main()
{
    int first,last,mid,n,i,find,a[100];

    printf("\nEnter the size of the array");
    scanf("%d",&n);

    printf("\nEnter the elements in ascending order");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("\nEnter the value to be searched");
    scanf("%d",&find);

    first=0;
    last=n-1;
    mid=(last+first)/2;

    while(first<last)
    {
        if(a[mid]<find)
            first=mid+1;
        else if(a[mid]==find)
        {
            printf("Element found at index %d\n",mid+1);
            break;
        }
        else
            last=mid-1;

        mid=(first+last)/2;

    }

    if(first>last)
        printf("Element not found");

    return 0;
}
