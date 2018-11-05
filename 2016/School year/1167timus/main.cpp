#include <iostream>

using namespace std;

int dp[510][510],i,j,n,k,w[510],b[510];

int main()
{
    cin>>n>>k;
    for (i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        w[i]=w[i-1];
        b[i]=b[i-1];
        if (x==0)
            w[i]++;
        else
            b[i]++;
    }
    for (i=1; i<=n; i++)
        dp[1][i]=w[i]*b[i];
    for (i=2; i<=k; i++)
    {
        for (j=i; j<=n; j++)
        {
            dp[i][j]=dp[i-1][i-1]+(w[j]-w[i-1])*(b[j]-b[i-1]);
            for (int z=i; z<j; z++)
                if (dp[i-1][z]+(w[j]-w[z])*(b[j]-b[z])<dp[i][j])
                    dp[i][j]=dp[i-1][z]+(w[j]-w[z])*(b[j]-b[z]);
        }
    }
    cout<<dp[k][n]<<'\n';
}
