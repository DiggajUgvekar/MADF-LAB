#include <stdio.h>
#include <stdbool.h>

#define MAX_N 100

bool G[MAX_N][MAX_N];
int m, n, x[MAX_N];

void NextValue(int k)
{
    do
    {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
            return;

        int j;
        for (j = 1; j <= n; j++)
        {
            if (G[k][j] && (x[k] == x[j]))
                break;
        }
        if (j == n + 1)
            return;
    } while (true);
}

void mColoring(int k)
{
    do
    {
        NextValue(k);
        if (x[k] == 0)
            return;
        if (k == n)
        {
            printf("Solution: ");
            for (int i = 1; i <= n; i++)
                printf("%d ", x[i]);
            printf("\n");
        }
        else
            mColoring(k + 1);
    } while (true);
}

int main()
{
    printf("Enter the number of vertices : ", MAX_N);
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &G[i][j]);

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    for (int i = 1; i <= n; i++)
        x[i] = 0;

    mColoring(1);

    return 0;
}
