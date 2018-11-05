#include <iostream>

using namespace std;

long long n,i,ans[50];

int main()
{
    ans[1]=2;
    ans[2]=2;
    for (i=3; i<=45; i++)
        ans[i]=ans[i-1]+ans[i-2];
    cin>>n;
    cout<<ans[n];
    return 0;
}
/*
    0=alb
    1=albastru
    2=rosu
    dp[i][0]=dp[i-2][2]+dp[i-1][2]
    dp[i][1]=0
    dp[i][2]=dp[i-2][0]+dp[i-1][0]
    dp[i]=dp[i][0]+dp[i][2]=d[i-2]+dp[i-1]
*/
