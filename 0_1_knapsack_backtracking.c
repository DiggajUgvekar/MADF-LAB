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
        if (c + weights[i] <= knapsackSize) {
            b += profits[i];
            c += weights[i];
        } else {
            double remainingCapacity = knapsackSize - c;
            b += profits[i] * (remainingCapacity / weights[i]);
            break;
        }
    }

    return b;
}

void knapsack(int currentIndex, int currentProfit, int currentWeight, int knapsackSize) {
    if (currentIndex == MAX_ITEMS) {
        if (currentProfit > maxProfit) {
            maxProfit = currentProfit;
            knapsackWeight = currentWeight;
            for (int i = 0; i < currentIndex; i++) {
                finalSolution[i] = 0;
            }
            for (int i = 0; i < currentIndex; i++) {
                finalSolution[i] = 1;
            }
        }
        return;
    }

    if (currentWeight + weights[currentIndex] <= knapsackSize) {
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
    
    
    printf("\n");

    return 0;
}
