#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 100

int p[MAX]={999,3,4,3,2,4};
int q[MAX]={4,4,5,4,5,4};
int w[MAX][MAX];
int c[MAX][MAX];
int r[MAX][MAX];

void display();

int find(int i,int j)
{
    int min=INT_MAX;
    int l;
    for(int m=i+1;m<=j;m++)
    {
        if(c[i][m-1]+c[m][j]<min)
        {
            min=c[i][m-1]+c[m][j];
            l=m;
        }
    }
    return l;
}

int main()
{
    int k;
    for(int i=0;i<=5;i++){
        w[i][i]=q[i];
        r[i][i]=0;
        c[i][i]=0;
    }
    for(int i=0;i<=3;i++){
       w[i][i+1]=q[i]+q[i+1]+p[i+1];

        r[i][i+1]=i+1;

        c[i][i+1]=q[i]+q[i+1]+p[i+1];
    }
    for(int m=1;m<=6;m++)
    {
        for(int i=0;i<=6-m;i++)
        {
           int j=i+m;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            k=find(i,j);
            c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
            r[i][j]=k;
        }
    }
display();
}

void display()
{
   int a=0;
   int i=0;
   int j=0;
   while(a<6)
   {
    i=0;
    j=a;
   while(i<6-a&&j<6){            
    printf("w[i][j]=%d\t",w[i][j]);
    i++;
    j++;
    }
    i=0;
    j=a;
    printf("\n");
    while(i<6-a&&j<6){
        printf("c[i][j]=%d\t",c[i][j]);
        i++;
        j++;
    } 
    i=0;
    j=a;
    printf("\n");

    while(i<6-a&&j<6){        
    printf("r[i][j]=%d\t",r[i][j]);
    i++;
    j++;
    }
    printf("\n------------------------------\n");
    a++;
}
}