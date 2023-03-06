#include <stdio.h>
#include <stdlib.h>
//Descending sort of numbers
int a[100];

void merge(int low,int mid,int high)
{
    int b[100];
    int h,i,j,k;
    h = low;
    i = low;
    j = mid+1;

    while((h <= mid) && (j <= high))
    {
        if(a[h]>=a[j])
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
            printf("%d ",a[i]);
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
        printf("%d ",a[i]);
    }
}

int main()
{
    int n,i,lo,hi;

    printf("Enter number of elements\n");
    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
        printf("Enter Element : ");
        scanf("%d",&a[i]);
    }
    lo = 0;
    hi = n-1;

    printf("\nMerge Sort Iterations (Descendig): \n");

    mergeSort(lo,hi,n);

    printf("\nAfter Sort: ");
    display(n);


    return 0;
}
