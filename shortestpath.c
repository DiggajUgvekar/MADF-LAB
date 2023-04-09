#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100

int cost[MAX][MAX];
int dist[MAX];
bool s[MAX];

int minDistance(int dist[], bool sptSet[],int n)
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 1; v <= n; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void shortestpath(int v,int e, int n){
    int i,num,u,min,w;
    
    for(i = 1; i <= n; i++){
        s[i] = false;
        dist[i] = cost[v][i];
        // dist[i] = INT_MAX;
    }
    s[v] = true;
    dist[v] = 0;

    for(num = 2; num <= n; num++){
        // min = INT_MAX;
         u = minDistance(dist, s,n);
        // for (int k = 1; k <= n; k++) {
        //     // if (!s[k] && dist[k] < min) {
        //     //     min = dist[k];
        //     //     u = k;
        //     // }
        //     if (s[k] == false && dist[k] <= min)
        //         min = dist[k], u = k;
        // }
        s[u] = true;

        for(w = 1; w<= n; w++){
            if((!s[w] && cost[u][w] && dist[u] != INT_MAX) && (dist[u]+cost[u][w] < dist[w])){
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }

    printf("Vertex \t Distance from Source\n");
    for (i = 1; i <= n; i++) {
      printf("%d \t %d\n", i, dist[i]);
    }

}
int main(){
    int n,cost1,i,j,e,s,d,v;
    v = 1;
    printf("Enter the number of vertex : ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cost[i][j] = cost[j][i] = 0;
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

    shortestpath(v,e,n);
    
    return 0;
}