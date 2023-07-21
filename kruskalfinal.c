#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <limits.h>
int i, j, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];
int find(int i)
{
	while (parent[i]){
	i = parent[i];
	}
	return i;
}
int uni(int i, int j)
{
	if (i != j){
	parent[j] = i;
	return 1;
	}
	return 0;
}
int main(){
	int c, origin, dest;
	printf("\nEnter the no. of vertices:");
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++){
		cost[i][j] = INT_MAX;
		}
	}
	int max_edges=(n*(n-1))/2;
	for (i=1; i<=max_edges; i++){
		printf("Enter origin and destination(-1 -1): ");
		scanf("%d %d", &origin, &dest);
		if (origin==-1 && dest==-1)
			break;
		printf("Enter cost: ");
		scanf("%d", &c);
		cost[origin][dest]=c;
		cost[dest][origin]=c;
	}
	printf("\n");
	while (ne < n){
		min = INT_MAX;
		for (i = 1; i <= n; i++){
			for (j = 1; j <= n; j++){
			if (cost[i][j] < min){
				min = cost[i][j];
				a = u = i;
				b = v = j;
			}
			}
		}
		u = find(u);
		v = find(v);
		if (uni(u, v)){
			mincost += min;
			ne++;
			printf("Step cost : %d\n",mincost);
		}
		cost[a][b] = cost[b][a] = INT_MAX;   //used to remove an edge from the graph once it has been added to the Minimum Spanning Tree
	}
	printf("\n=> Minimum cost = %d\n",mincost);
	return 0;
}
