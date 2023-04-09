#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 100

int g[MAX][MAX];
float cost[MAX];
int p[MAX];
int d[MAX];

void fgraph(int n,int e, int k){
    int j,r,i;
    cost[n] = 0.0;

    for(j = n -1; j >= 1; j--){
        r = -1;

        for (i = 1; i <= n; i++) {
            if (g[j][i] != INT_MAX) {
                if (r == -1 || g[j][i] + cost[i] < g[j][r] + cost[r]) {
                    r = i;
                }
            }
        }
        cost[j] = g[j][r] + cost[r];
        d[j] = r;
    }
    p[1] = 1;
    p[k] = n;
    for(j = 2; j<= k-1; j++){
        p[j] = d[p[j-1]];
    }
}
int main(){
    int n,k,e,s,d,cost1,i;
    printf("Enter the no. of vertics : ");
    scanf("%d",&n);
    printf("Enter the no. of stages : ");
    scanf("%d",&k);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            g[i][j] = g[j][i] = INT_MAX;
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
        g[s][d] = cost1;
    }
    fgraph(n,e,k);

    printf("The Path is : with Cost = %.2f\n",cost[1]);
    for(i = 1; i <= k; i++){
        printf("-> %d ",p[i]);
    }
    return 0;
}