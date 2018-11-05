#include <iostream>

using namespace std;

long long n,i,j,fact[15],dp[11][11];
long long ans[11];

int main()
{
    fact[0]=fact[1]=1;
    for (i=2; i<=13; i++)
        fact[i]=fact[i-1]*i;
    for (i=1; i<=10; i++)
        dp[i][i]=fact[i];
    for (i=2; i<=10; i++)
        for (j=i; j; j--)
            dp[i][j]=j*(dp[i-1][j]+dp[i-1][j-1]);
    for (i=1; i<=10; i++)
        for (j=1; j<=10; j++)
            ans[i]+=dp[i][j];
    cin>>n;
    while (n!=-1)
    {
        cout<<ans[n]<<'\n';
        cin>>n;
    }
    return 0;
}
