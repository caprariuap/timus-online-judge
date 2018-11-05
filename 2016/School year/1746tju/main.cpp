#include <iostream>
#include <cstdio>
using namespace std;

int n,i,j,k;
int c1[610][500],c2[610][500],ANS[610][500];

int adunare(int A[], int B[])
{
    int i,T=0;
    if (B[0]>A[0])
    {
        for (i=A[0]+1; i<=B[0];) A[i++]=0;
        A[0]=B[0];
    }
    else for (i=B[0]+1; i<=A[0];) B[i++]=0;
    for (i=1; i<=A[0]; i++)
    {
        A[i]+=B[i]+T;
        T=A[i]/10;
        A[i]%=10;
    }
    if (T) A[++A[0]]=T;
}

int main()
{
    n=600;
    for(i=0; i<=600; i++)
    {
        c1[i][0]=c1[i][1]=1;
        c2[i][0]=1;
        c2[i][1]=0;
    }
    for(i=2; i<=n; i++)
    {
        for(j=0; j<=n; j++)
            for(k=0; k+j<=n; k+=i)
            {
                adunare(c2[k+j],c1[j]);
            }
        for(int m=0; m<=n; m++)
        {
            int L=c2[m][0];
            for (int mm=0; mm<=L; mm++)
            {
                c1[m][mm]=c2[m][mm];
                c2[m][mm]=0;
            }
        }
        for (int z=0; z<=c1[i][0]; z++)
        ANS[i][z]=c1[i][z];
    }
    ANS[1][1]=ANS[1][0]=1;
    while(scanf("%d",&n)&&n)
    {
        for (i=ANS[n][0]; i; i--)
            printf("%d",ANS[n][i]);
        printf("\n");
    }
}
/*
dp[i][j]=nr de moduri de a scrie i ca suma de j elemente
dp[n+k][k]=dp[n][1]+dp[n][2]+...+dp[n][k]
dp[n]=nr de moduri de a scrie n ca suma de nr naturale
dp[n]=dp[n][1]+dp[n][2]+...+dp[n][n]
dp[n][k]=dp[n-k+k][k]=dp[n-k][1]+dp[n-k][2]+...+dp[n-k][k]
DP[i][j]=nr de moduri de a scrie i ca suma de maxim j elemente
DP[n][n]=dp[n]
DP[n][k]=dp[n][1]+dp[n][2]+...+dp[n][k]
DP[n][k]=dp[n-k+k][k]+dp[n-k+k][k-1]+...+dp[n-k+k][1]
*/
