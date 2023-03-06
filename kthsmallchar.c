#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
char a[100];

void sw(char a[], int x, int b)
{
    char t = a[x];
    a[x] = a[b];
    a[b] = t;
}

int partition(char a[], int p, int q)
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

char kthsmall(char a[], int n, int k){
    int low,up,j,i;
    low = 1;
    up = n+1;
    a[up] = CHAR_MAX;

    while(low<=up){
        
        j = partition(a,low,up);
        if(k == j)
        {
            for (i = 1; i <= n; i++)
                printf("%c ", a[i]);
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
            printf("%c ", a[i]);
        printf("\n");
    }
}


int main()
{
    int i,size, k;
    char data;
    printf("Enter number of elements : ");
    scanf("%d", &size);

    printf("Enter elements : ");
    for (i = 1; i <= size; i++)
    {
        scanf(" %c", &a[i]);
    }
    printf("Which kth smallest to find ?\n");
    scanf("%d", &k);

    printf("\nIterations : \n");
    data = kthsmall(a,size,k);
    printf("The %dth smallest element is %c",k,data);

    return 0;
}