#include <stdio.h>
#include <stdlib.h>
// int a[4][4] = {
//    {4,2,0,1},
//    {3,1,2,5},
//    {3,2,1,4},
//    {5,2,6,7} 
// };

// int b[4][4] = {
//     {2,1,3,2},
//     {5,4,2,3},
//     {1,4,0,2},
//     {3,2,4,1}
// };

int a[4][4];
int b[4][4];
int c[4][4];

int temp[2][2],temp2[2][2];
int p1[2][2], q1[2][2],r1[2][2],s1[2][2],t1[2][2],u1[2][2],v1[2][2];

void display(int z[2][2]);
void multiple2x2(int temp[2][2],int temp2[2][2],int z[2][2]);
int main()
{
    
    int i, j;
    //Init Matrix
    printf("A Matrix\n");
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("\nB Matrix\n");
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            scanf("%d",&b[i][j]);
        }
    }

    //P
    for ( i = 0; i < 2; ++i) {
      for ( j = 0; j < 2; ++j) {
            temp[i][j] = 0;
            temp2[i][j] = 0;
            temp[i][j] += ((a[i][j] )+ (a[i+2][j+2]));
            temp2[i][j] += ((b[i][j] )+ (b[i+2][j+2]));
         }
      }
    multiple2x2(temp,temp2,p1);
    printf("P Matrix\n");
    display(p1);

    //Q
    for ( i = 0; i < 2; ++i) {
      for ( j = 0; j < 2; ++j) {
            temp[i][j] = 0;
            temp2[i][j] = 0;
            temp[i][j] += ((a[i+2][j] )+ (a[i+2][j+2]));
            temp2[i][j] += (b[i][j]);
         }
      }
    multiple2x2(temp,temp2,q1);
    printf("Q Matrix\n");
    display(q1);

    //R
    for ( i = 0; i < 2; ++i) {
      for ( j = 0; j < 2; ++j) {
            temp[i][j] = 0;
            temp2[i][j] = 0;
            temp[i][j] += (a[i][j]);
            temp2[i][j] += (b[i][j+2] - b[i+2][j+2]);
         }
      }
    multiple2x2(temp,temp2,r1);
    printf("R Matrix\n");
    display(r1);

    //S
    for ( i = 0; i < 2; ++i) {
      for ( j = 0; j < 2; ++j) {
            temp[i][j] = 0;
            temp2[i][j] = 0;
            temp[i][j] += (a[i+2][j+2]);
            temp2[i][j] += (b[i+2][j] - b[i][j]);
         }
      }
    multiple2x2(temp,temp2,s1);
    printf("S Matrix\n");
    display(s1);


    //T
    for ( i = 0; i < 2; ++i) {
      for ( j = 0; j < 2; ++j) {
            temp[i][j] = 0;
            temp2[i][j] = 0;
            temp[i][j] += ((a[i][j]) + (a[i][j+2]));
            temp2[i][j] += (b[i+2][j+2]);
         }
      }
    multiple2x2(temp,temp2,t1);
    printf("T Matrix\n");
    display(t1);

    //U
    for ( i = 0; i < 2; ++i) {
      for ( j = 0; j < 2; ++j) {
            temp[i][j] = 0;
            temp2[i][j] = 0;
            temp[i][j] += ((a[i+2][j]) - (a[i][j]));
            temp2[i][j] += (b[i][j] + b[i][j+2]);
         }
      }
    multiple2x2(temp,temp2,u1);
    printf("U Matrix\n");
    display(u1);

    //V
    for ( i = 0; i < 2; ++i) {
      for ( j = 0; j < 2; ++j) {
            temp[i][j] = 0;
            temp2[i][j] = 0;
            temp[i][j] += ((a[i][j+2]) - (a[i+2][j+2]));
            temp2[i][j] += (b[i+2][j] + b[i+2][j+2]);
         }
      }
    multiple2x2(temp,temp2,v1);
    printf("V Matrix\n");
    display(v1);

   //Final Matrix Calculation
   for ( i = 0; i < 2; ++i) {
      for ( j = 0; j < 2; ++j) {
         //c11
         c[i][j] = ((p1[i][j] + s1[i][j]) - t1[i][j]) + v1[i][j];
         //c12
         c[i][j+2] = r1[i][j] + t1[i][j];
         //c21
         c[i+2][j] = q1[i][j] + s1[i][j];
         //c22
         c[i+2][j+2] = ((p1[i][j] + r1[i][j]) - q1[i][j]) + u1[i][j];
         }
      }
   printf("\nC Matrix\n");
   for ( i = 0; i < 4; ++i) {
      printf("|");
      for ( j = 0; j < 4; ++j) {
            printf("%d ",c[i][j]);
         }
      printf("|");
      printf("\n");
      }
    return 0;
}


void display(int z[2][2])
{
    int i, j;
    for(i = 0; i < 2; i++){
        printf("|");
        for(j = 0; j < 2; j++){
             printf("%d ",z[i][j]);
         }
        printf("|");
        printf("\n");
    }
}
void multiple2x2(int temp[2][2],int temp2[2][2], int z[2][2])
{
    int p,q,r,s,t,u,v;
    p = (temp[0][0] + temp[1][1]) * (temp2[0][0] + temp2[1][1]);
    q = (temp[1][0] + temp[1][1]) * (temp2[0][0]);
    r = temp[0][0] * (temp2[0][1] - temp2[1][1]);
    s = temp[1][1] * (temp2[1][0] - temp2[0][0]);
    t = (temp[0][0] + temp[0][1]) * (temp2[1][1]);
    u = (temp[1][0] - temp[0][0]) * (temp2[0][0] + temp2[0][1]);
    v = (temp[0][1] - temp[1][1]) * (temp2[1][0] + temp2[1][1]);

    
    z[0][0] = p + s - t + v;
    z[0][1] = r + t;
    z[1][0] = q + s;
    z[1][1] = p + r - q + u;
}