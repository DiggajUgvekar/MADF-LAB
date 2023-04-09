#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//binary search
char a[100];

int binarySearch(char a[],int low, int high,char x,int n)
{
    int mid,i;
    if(low==high)
    {
        if(a[low] == x)
        {
            return low;
        }
        return -1;
    }
    else
    {
        mid = (low+high)/2;
        if(a[mid] == x)
        {
            for(i = 0; i < n; i++)
            {
            printf(" %c",a[i]);
            }
            return mid;
        }
        else if(x > a[mid])
        {
            for(i = 0; i < n; i++)
            {
            printf(" %c",a[i]);
            }
            printf("   mid = %d\n",mid);
            return binarySearch(a,mid+1,high,x,n);
        }
        else
        {
            for(i = low; i < n; i++)
            {
            printf(" %c",a[i]);
            }
            printf("   mid = %d\n",mid);
            return binarySearch(a,low,mid-1,x,n);
        }
    }
    
}

int main(){
    int n,i,lo,hi,pos=0;
    char x;
    printf("Enter number of elements\n");
    scanf("%d",&n);

    printf("Enter Element : ");
    for(i = 0; i < n; i++)
    {
        scanf(" %c",&a[i]);
    }
    lo = 0;
    hi = n-1;

    
    printf("\n\nEnter element to Search : ");
    scanf(" %c",&x);
    
    pos = binarySearch(a,lo,hi,x,n);
    if(pos == -1)
    {
        printf("mid = %d",pos);
        printf("\nElement %c not found",x);
    }
    else{
        printf("   mid = %d",pos);
        printf("\nElement is at position %d",pos);
    }
    printf("\n");

    return 0;
}
