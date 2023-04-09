#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100

int cost[MAX][MAX];
int A[MAX][MAX];

int min(int a, int b){
    if(a > b){
        return b;
    }
}
void allpairshort(int n, int e){
    int i,j,k,count = 0;
    for(i = 1; i <= n; i++){
        cost[i][i] = 0;
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            A[i][j] = cost[i][j];
        }
    }
    //display A0 Matrix
    printf("\nA0 = \n");
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if (A[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d ", A[i][j]);
            }

        }
        printf("\n");
    }
    for(k = 1; k <= n; k++){
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                
                if (A[i][k] != INT_MAX && A[k][j] != INT_MAX) {
                    A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
                }
            }
        }
        //display all the A1 to An matrix
        printf("\nA%d = \n",k);
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                if (A[i][j] == INT_MAX) {
                    printf("INF ");
                } else {
                    printf("%d ", A[i][j]);
                }
            }
            printf("\n");
        }
    }
}

int main()
{
    int n, e, s, d, cost1,i,j;
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

    allpairshort(n, e);

    return 0;
}