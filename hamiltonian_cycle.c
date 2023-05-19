#include <stdio.h>
#define MAX_NODES 20

int graph[MAX_NODES][MAX_NODES];
int count = 0;

void print(int x[MAX_NODES], int n)
{
    printf("%d)\t", ++count);
    for (int i = 1; i <= n; i++)
        printf("%d ", x[i]);
    printf("%d\n",x[1]);
}

void next_value(int x[MAX_NODES], int n, int k)
{
     do {
        x[k] = (x[k] + 1) % (n + 1); 
        if (!x[k]) return; 
        if (graph[x[k-1]][x[k]] != 0) 
        { 
            int j;
            for (j = 1; j < k; j++)
                if (x[j] == x[k]) break; 
            if (j == k && ((k < n) || (k == n && graph[x[n]][x[1]]))) return; 
        }
    } while (1);
}

void hamiltonian(int x[MAX_NODES], int n, int k)
{
    do
    {
        next_value(x, n, k);
        if (!x[k])
            return;
        if (k == n)
            print(x, n);
        else
            hamiltonian(x, n, k + 1);

    } while (1);
}

void create_graph(int n)
{
    int max = n * n;
    int origin, destination;
    printf("Enter the edges of the graph (-1 -1 to quit):\n");
    for (int i = 1; i <= max; i++)
    {
        scanf("%d %d", &origin, &destination);
        if ((origin == -1) && (destination == -1))
            break;
        if (origin > n || destination > n || origin <= 0 || destination <= 0)
        {
            printf("Edge is Invalid\n");
            i--;
        }
        else
        {
            graph[origin][destination] = 1;
            graph[destination][origin] = 1;
        }
    }
}

int main()
{
    int n, x[MAX_NODES];
    printf("Enter the no of nodes : ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <=n; j++)
            graph[i][j] = 0;

    create_graph(n);
    for (int i = 1; i <= n; i++)
        x[i] = 0;
      
    printf("\nHAMILTONIAN CYCLES\n");

    x[1] = 1; 
    hamiltonian(x,n,2);
    if (count == 0) 
        printf("\nNo Hamiltonian cycles found\n");
    else 
        printf("\nFound %d Hamiltonian cycles\n", count);  
    return 0;
}
