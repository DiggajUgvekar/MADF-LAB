#include<stdio.h>
#define MAX 15
int x[6];
int w[MAX];
int w_sum;
int m;
int n;
void sumofsubset(int s,int k,int r);
void write(int x[MAX],int k);
int main()
{
    int s=0,k=0;
    int r;
    printf("Enter number of weights : ");
    scanf("%d",&n);
    printf("Enter Weights : ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&w[i]);
        w_sum = w_sum+w[i];
    }
    r = w_sum;
    printf("Enter total sum : ");
    scanf("%d",&m);
    printf("\n\n");
    for(int i=0;i<n;i++)
    {
        printf("x%d\t",i+1);

    }
    printf("\n");

    sumofsubset(s,k,r);
    
}
void sumofsubset(int s,int k,int r)
{
    //generate left child
    x[k]=1;
    if(s+w[k]==m)
     write(x,k);

    else if(s+w[k]+w[k+1]<=m)
    sumofsubset(s+w[k],k+1,r-w[k]);

    //generate right child
    if((s+r-w[k]>=m)&&(s+w[k+1]<=m))
    {
    x[k]=0;
    sumofsubset(s,k+1,r-w[k]);
    }
}

void write(int x[MAX],int k)
{
	if(k!=n)
	{
		for(int i=k+1;i<n;i++)
		x[i]=0;
	}
    for(int i=0;i<n;i++)
    {
        printf("%d\t",x[i]);
    }
    printf("\n");
}