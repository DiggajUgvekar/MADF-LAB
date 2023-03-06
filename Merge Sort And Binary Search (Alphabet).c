#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Ascending sort and search of character array
char a[100];

void merge(int low,int mid,int high)
{
    int b[100];
    int h,i,j,k;
    h = low;
    i = low;
    j = mid+1;
    while((h <= mid) && (j <= high))
    {
        if(a[h]<=a[j])
        {
            b[i] = a[h];
            h = h+1;
        }
        else
        {
            b[i] = a[j];
            j = j + 1;
        }
        i = i+1;
    }

    if(h > mid)
    {
        for(k = j; k <= high; k++)
        {
            b[i] = a[k];
            i = i + 1;
        }
    }
    else
    {
        for(k = h; k <= mid; k++)
        {
            b[i] = a[k];
            i = i+1;
        }
    }

    for( k = low; k <= high; k++)
    {
        a[k] = b[k];
    }
}

void mergeSort(int low,int high,int n)
{
    int mid,i;
    if(low<high)
    {
        mid = (low + high)/2;
        
        
        mergeSort(low,mid,n);
        mergeSort(mid+1,high,n);
        
        for(i = 0; i < n; i++)
        {
            printf(" %c",a[i]);
        }
        printf("\n");
        merge(low,mid,high);
    }
}

void display(int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf(" %c",a[i]);
    }
}

int binarySearch(char a[],int low, int high,char x)
{
int mid,i;
if(x == '@')
{
    exit(1);
}
    if(low==high)
    {
        if(a[low] == x)
        {
            return low;
        }
        else
            return -1;
    }
    else
    {
        mid = (low+high)/2;
        if(a[mid] == x)
        {
            return mid;
        }
        else if(x > a[mid])
        {
            for(i = low; i <= high; i++)
            {
            printf(" %c",a[i]);
            }
            printf("\nmid = %d\n",mid);
            return binarySearch(a,mid+1,high,x);
        }
        else
        {
            for(i = low; i <= high; i++)
            {
            printf(" %c",a[i]);
            }
            printf("\nmid = %d\n",mid);
            return binarySearch(a,low,mid-1,x);
        }
    }
}
int main()
{
    int n,i,lo,hi,pos=0;
    char x;
    printf("Enter number of elements\n");
    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
       
        printf("Enter Element : ");
        scanf(" %c",&a[i]);
    }
    lo = 0;
    hi = n-1;

    printf("\nMerge Sort Iterations : \n");

    mergeSort(lo,hi,n);

    printf("\nAfter Sort: ");
    display(n);

    do{
    printf("\n\nEnter element to Search : ");
    scanf(" %c",&x);

    pos = binarySearch(a,lo,hi,x);
    if(pos == -1)
    {
        printf("mid = %d",pos);
        printf("\nElement %d not found",x);
    }
    else{
        printf("mid = %d",pos);
        printf("\nElement is at position %d",pos);
    }
    
    printf("\n");
    }while(x!='@');
    return 0;
}
