#include<stdio.h>
#define MAX_ITEMS 100

void knapsack(int n, int weight[MAX_ITEMS], int profit[MAX_ITEMS], int maxWeight, int knapsackTable[MAX_ITEMS][MAX_ITEMS], int selected[MAX_ITEMS]){
    int i,j,k;
    for(i=0;i<=n;i++){
        knapsackTable[i][0]=0;
    }
    for(j=0;j<=maxWeight;j++){
        knapsackTable[0][j]=0;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=maxWeight;j++){
            if(weight[i]>j){
                knapsackTable[i][j]=knapsackTable[i-1][j];
            }
            else{
                if(knapsackTable[i-1][j]>profit[i]+knapsackTable[i-1][j-weight[i]]){
                    knapsackTable[i][j]=knapsackTable[i-1][j];
                }else{
                    knapsackTable[i][j]=profit[i]+knapsackTable[i-1][j-weight[i]];
                }
            }
        }
    }
    i=n;
    k=maxWeight;
    while(i>0 && k>0){
        if(knapsackTable[i][k]!=knapsackTable[i-1][k]){
            selected[i]=1;
            k=k-weight[i];
        }
        i=i-1;
    }
}

int main(){
    int i,j,n,maxWeight,profitSum,weightSum;
    int weight[MAX_ITEMS], profit[MAX_ITEMS], knapsackTable[MAX_ITEMS][MAX_ITEMS], selected[MAX_ITEMS];
    printf("Enter the number of items: ");
    scanf("%d",&n);
    printf("Enter the maximum knapsack weight: ");
    scanf("%d",&maxWeight);
    printf("\nWeight of items\n");
    for(i=1;i<=n;i++){
        printf("Enter weight and profit of item %d: ",i);
        scanf("%d",&weight[i]);
        scanf("%d",&profit[i]);
    }
    knapsack(n,weight,profit,maxWeight,knapsackTable,selected);
    profitSum=0;
    weightSum=0;
    for(i=1;i<=n;i++){
        profitSum+=selected[i]*profit[i];
        weightSum+=selected[i]*weight[i];
    }
    printf("Max Profit: %d\n",profitSum);
    printf("Optimal weight: %d\n",weightSum);
    return 0;
}
