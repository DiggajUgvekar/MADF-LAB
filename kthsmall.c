#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int a[100];

void sw(int a[], int x, int b)
{
    int t = a[x];
    a[x] = a[b];
    a[b] = t;
}

int partition(int a[], int p, int q)
{
    int i,j,pivot;
    pivot = a[q], i = p - 1, j;
    for (j = p; j < q; j++)
    {

        if (a[j] < pivot)
        {

            i++;
            sw(a, i, j);
        }
    }
    sw(a, i + 1, q);
    return i + 1;
}

int kthsmall(int a[], int n, int k){
    int low,up,j,i;
    low = 1;
    up = n+1;
    a[up] = INT_MAX;

    while(low<=up){
        
        j = partition(a,low,up);
        if(k == j)
        {
            for (i = 1; i <= n; i++)
            printf("%d, ", a[i]);
            printf("\n");
            return a[j];
        }
        else if(k > j)
        {
            low = j + 1;
        }
        else{
            up = j-1;
        }
        for (i = 1; i <= n; i++)
        printf("%d, ", a[i]);
        printf("\n");
    }
}


int main()
{
    int i,size,k,data;
    printf("Enter number of elements : ");
    scanf("%d", &size);

    printf("Enter elements : ");
    for (i = 1; i <= size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Which kth smallest to find ?\n");
    scanf("%d", &k);

    printf("\nIterations : \n");
    data = kthsmall(a,size,k);
    printf("The %dth smallest element is %d",k,data);

    return 0;
}