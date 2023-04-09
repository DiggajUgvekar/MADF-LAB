#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100

int cost[MAX][MAX];
int dist[MAX];

void bellmanford(int v, int n, int e){
    int i,k,j;
    for(i = 1; i <= n; i++){
        dist[i] = cost[v][i];
    }
    dist[v] = 0;

    
    for(k = 2; k <= n-1; k++){
        for (int u = 1; u <= n; u++) {
            
            for (int i = 1; i <= n; i++) {
               
                if(i != v) {
                for(j = 1; j <= n; j++) {
                    if(cost[i][j] != INT_MAX){
                        if(dist[j] > dist[i] + cost[i][j]) {
                            dist[j] = dist[i] + cost[i][j];
                        }
                    }
                }
            }
            
            }
    }
}
}
int main()
{
    int n, e, s, d, cost1,i,j,v = 1;
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
        cost[s][d] = cost1;
    }

    bellmanford(v, n, e);
    
    printf("Shortest distance from source vertex %d :\n", v);
    for (int i = 1; i <= n; i++) {
            printf("Vertex %d : %d\n",i,dist[i]);
        }

    return 0;
}