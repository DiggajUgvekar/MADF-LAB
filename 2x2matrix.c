#include<stdio.h>
#include<stdlib.h>
int a[2][2], b[2][2];
int c[2][2];

int main()
{
    int i,j,p,q,r,s,t,u,v;
    printf("A matrix\n");
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("B matrix\n");
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            scanf("%d",&b[i][j]);
        }
    }
    
    p = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    q = (a[1][0] + a[1][1]) * (b[0][0]);
    r = a[0][0] * (b[0][1] - b[1][1]);
    s = a[1][1] * (b[1][0] - b[0][0]);
    t = (a[0][0] + a[0][1]) * (b[1][1]);
    u = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    v = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

    printf("\np = %d",p);
    printf("\nq = %d",q);
    printf("\nr = %d",r);
    printf("\ns = %d",s);
    printf("\nt = %d",t);
    printf("\nu = %d",u);
    printf("\nv = %d\n\n",v);

    c[0][0] = p + s - t + v;
    c[0][1] = r + t;
    c[1][0] = q + s;
    c[1][1] = p + r - q + u;
    
    printf("C Matrix\n");
    for (i = 0; i < 2; i++){
        printf("|");
        for (j = 0; j < 2; j++){
            printf("%d ",c[i][j]);
        }
        printf("|");
        printf("\n");
    }
    return 0;
}