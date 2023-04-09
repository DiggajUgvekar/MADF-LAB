#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100

int cost[MAX][MAX];
int t[MAX][MAX];
int near[MAX];
int prim(int n, int e);

int main()
{
    int n, e, s, d, cost1, mincost;
    printf("Enter the number of vertex : ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cost[i][j] = cost[j][i] = INT_MAX;
        }
    }

    printf("Enter the number of edges : ");
    scanf("%d", &e);
    for (int i = 0; i < e; i++)
    {
        printf("Source : ");
        scanf("%d", &s);
        printf("Destination : ");
        scanf("%d", &d);
        printf("Cost : ");
        scanf("%d", &cost1);
        // save both at 1,2 and 2,1 (undirected graph)
        cost[s][d] = cost[d][s] = cost1;
    }

    mincost = prim(n, e);
    printf("Total MinCost = %d ", mincost);
}

int prim(int n, int e)
{
    int k, l, mincost;
    k = 1;
    l = 1;
    mincost = INT_MAX;
    //FIND MINIMUM COST EDGE
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (cost[i][j] < mincost)
            {
                k = i;
                l = j;
                mincost = cost[i][j];
            }
        }
    }

    mincost = cost[k][l];
    t[1][1] = k;
    t[1][2] = l;
    for (int i = 1; i <= n; i++)
    {
        if (cost[i][l] < cost[i][k])
        {
            near[i] = l;
        }
        else
        {
            near[i] = k;
        }
    }
    near[k] = near[l] = 0;
    

    int i = l, j = k, min = INT_MAX;
    for (int i = 2; i <= n - 1; i++)
    {
        min = INT_MAX;
        for (int k = 1; k <= n; k++)
        {
            if (near[k] != 0 && cost[k][near[k]] < min)
            {
                j = k;
                min = cost[k][near[k]];
            }
        }

        t[i][1] = j;
        t[i][2] = near[j];
        printf("Step %d (cost) : %d\n",i-1,mincost);
        mincost = mincost + cost[j][near[j]];

        near[j] = 0;
        for (int k = 1; k <= n; k++)
        {
            if (near[k] != 0 && cost[k][near[k]] >= cost[k][j])
            {
                near[k] = j;
            }
        }
    }
    return mincost;
}
