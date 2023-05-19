#include<stdio.h>
#include <math.h>
int Board[16], count;

int place(int row, int column)
{
    int i;
    for(i=1; i<=row-1; ++i)
    {
        if(Board[i] == column)
        {
            return 0;
        }
        else
        {
            if(abs(Board[i]-column) == abs(i-row))
            {
                return 0;
            }
        }
    }
    return 1; 
}

void display(int n)
{
    int i,j;
    printf("\n\nSolution %d:\n\n", ++count);
    for(i=1; i<=n; ++i)
        printf("\t%d", i);

    for(i=1; i<=n; ++i)
    {
        printf("\n\n%d",i);
        for(j=1;j<=n; ++j)
        {
            if(Board[i] == j)
            {
                printf("\tQ");
            }
            else
            {
                printf("\t.");
            }
        }
    }
    printf("\n\n");
}

void Queen(int row,int n)
{    
    int col;
    for(col = 1; col<=n; ++col)
    {
        if(place(row, col))
        {
            Board[row]= col; 
            if(row == n) 
            {
                display(n);   
            }
            else 
            {
            Queen(row+1, n);
            }
        }
    }
}


int main()
{
    int n, i, j;
    void Queen(int row,int n);

    printf("\n\nEnter number of Queens:");
    scanf("%d",&n);
    Queen (1,n);
    return 0;
}