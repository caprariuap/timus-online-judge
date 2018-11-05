#include <iostream>

using namespace std;

int n,k,i;
long long dp[50][2],dp2[50];

int main()
{
    cin >> n >> k;
    dp[1][0]=dp[1][1]=1;
    dp2[1]=2;
    for (i=2; i<=n; i++)
    {
        dp[i][0]=dp[i-1][1]+dp[i-1][0];
        dp[i][1]=dp[i-1][0];
        dp2[i]=dp[i][0]+dp[i][1];
    }
    if (k>dp[n][0]+dp[n][1])
    {
        cout << "-1\n";
        return 0;
    }
    for (i=n; i; i--)
    {
        if (dp[i][0]>=k)
        {
            cout << '0';
        }
        else
        {
            cout << '1';
            k-=dp[i][0];
        }
    }
    cout << '\n';
}
