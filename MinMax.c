#include <stdio.h>
#define MAX 9
int a[MAX];

void minmax(int i, int j, int *max, int *min,int n)
{
    int mid, max1, min1,z;
    if (i == j)
    {
        *max = a[i];
        *min = a[i];
        return;
    }
    else if (i == j - 1)
    {
        if (a[i] > a[j])
        {
            *max = a[i];
            *min = a[j];
        }
        else
        {
            *max = a[j];
            *min = a[i];
        }
        return;
    }
    else
    {
        mid = (i + j) / 2;
        minmax(i, mid, max, min,n);
        minmax(mid + 1, j, &max1, &min1,n);
        if (max1 > *max)
            *max = max1;
        if (min1 < *min)
            *min = min1;
    }
}

int main()
{
    int i,n, min = 0, max = 0,size;
    printf("Enter no. of elements :\n");
    scanf("%d",&n);
    printf("Enter Elements : ");
    for (i = 0; i <n; i++)
    {
        scanf("%d", &a[i]);
    }
    size = n-1;
    minmax(0, size, &max, &min,n);
    printf("Max is %d\n", max);
    printf("Min is %d\n", min);
}