#include <stdio.h>

#define MAX_ITEMS 100

int maxProfit = 0;
int knapsackWeight = 0;
int finalSolution[MAX_ITEMS];
int weights[MAX_ITEMS];
int profits[MAX_ITEMS];

int bound(int currentProfit, int currentWeight, int lastIndex, int knapsackSize) {
    int b = currentProfit;
    int c = currentWeight;

    for (int i = lastIndex + 1; i < MAX_ITEMS; i++) {
        c += weights[i];
        if (c < knapsackSize) {
            b += profits[i];
        } else {
            return b + ((1 - (c - knapsackSize) / weights[i]) * profits[i]);
        }
    }

    return b;
}

void knapsack(int currentIndex, int currentProfit, int currentWeight, int knapsackSize) {
    if (currentWeight <= knapsackSize && currentProfit > maxProfit) {
        maxProfit = currentProfit;
        knapsackWeight = currentWeight;
        for (int i = 0; i < currentIndex; i++) {
            finalSolution[i] = 1;
        }
    }

    if (bound(currentProfit, currentWeight, currentIndex, knapsackSize) > maxProfit) {
        finalSolution[currentIndex] = 1;
        knapsack(currentIndex + 1, currentProfit + profits[currentIndex], currentWeight + weights[currentIndex], knapsackSize);
    }

    if (bound(currentProfit, currentWeight, currentIndex, knapsackSize) > maxProfit) {
        finalSolution[currentIndex] = 0;
        knapsack(currentIndex + 1, currentProfit, currentWeight, knapsackSize);
    }
}

int main() {
    int n, knapsackSize;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the knapsack size: ");
    scanf("%d", &knapsackSize);

    printf("Enter the weights and profits of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Weight[%d]: ", i);
        scanf("%d", &weights[i]);
        printf("Profit[%d]: ", i);
        scanf("%d", &profits[i]);
    }

    knapsack(0, 0, 0, knapsackSize);

    printf("Maximum Profit: %d\n", maxProfit);
    printf("Knapsack Weight: %d\n", knapsackWeight);
    

    return 0;
}
