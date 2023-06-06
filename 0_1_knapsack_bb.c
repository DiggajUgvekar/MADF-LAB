#include <stdio.h>

int maxProfit = 0; // Global variable to store the maximum profit
int maxWeight = 0; // Global variable to store the maximum weight

void AlgorithmUBound(int cp, int cw, int k, int m, int w[], int p[], int n) {
    int b = cp;
    int c = cw;
    
    for (int i = k + 1; i < n; i++) {
        if (c + w[i] < m) {
            c += w[i];
            b -= p[i];
        }
    }
    
    if (b > maxProfit && c <= m) {
        maxProfit = b;
        maxWeight = c;
    }
}

void Knapsack(int cp, int cw, int k, int m, int w[], int p[], int n) {
    if (k == n - 1) {
        if (cp > maxProfit && cw <= m) {
            maxProfit = cp;
            maxWeight = cw;
        }
        return;
    }
    
    AlgorithmUBound(cp, cw, k, m, w, p, n);
    
    if (cp + p[k+1] > maxProfit && cw + w[k+1] <= m) {
        Knapsack(cp + p[k+1], cw + w[k+1], k + 1, m, w, p, n);
    }
    
    Knapsack(cp, cw, k + 1, m, w, p, n);
}

int main() {
    int n; // Number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    int w[n], p[n]; // Arrays to store weights and profits
    
    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    
    printf("Enter the profits of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    
    int m; // Maximum capacity of the knapsack
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &m);
    
    Knapsack(0, 0, -1, m, w, p, n);
    
    printf("Maximum Profit: %d\n", maxProfit);
    printf("Maximum Weight: %d\n", maxWeight);
    
    return 0;
}
