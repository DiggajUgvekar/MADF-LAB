#include <stdio.h>

void sw(int a[], int x, int b);
int quicksort(int a[], int p, int q,int size);
int partition(int a[], int p, int q);


int main()
{
    int i,size;
    printf("Enter number of elements : ");
    scanf("%d", &size);
    int a[size];
    printf("Enter elements : ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\nQuick Sort Iterations\n");
    quicksort(a, 0, size - 1,size);
    printf("Sorted array \n");
    for (i = 0; i < size; i++)
        printf("%d, ", a[i]);
    printf("\n");
}

void sw(int a[], int x, int b)
{
    int t = a[x];
    a[x] = a[b], a[b] = t;
}

int quicksort(int a[], int p, int q,int size)
{
    int pivot,i;

    if (p < q)
    {

        pivot = partition(a, p, q);
        for (i = 0; i < size; i++)
            printf("%d, ", a[i]);
        printf("\n");
        quicksort(a, p, pivot - 1,size);
        quicksort(a, pivot + 1, q,size);
    }
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