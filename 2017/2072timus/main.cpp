#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map <int, int> st,dr,ap;
int n,i,curent,a[100010],nr;
long long dp[100010][3];

long long calc(int curent, int val, int target)
{
    int p,u;
    p=st[val];
    u=dr[val];
    if (target==1)
    {
        if (curent<=p)
            return u-curent+ap[val];
        else if (curent<=u)
            return curent-p+u-p+ap[val];
        else
            return curent-p+u-p+ap[val];
    }
    if (curent>=u)
        return curent-p+ap[val];
    else if (curent>=p)
        return u-curent+u-p+ap[val];
    return u-curent+u-p+ap[val];
}

int main()
{
    cin >> n;
    for (i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        ap[x]++;
        if (st[x]==0)
            st[x]=i,a[++nr]=x;
        else if (i>dr[x])
            dr[x]=i;
    }
    sort(a+1,a+nr+1);
    for (i=1; i<=nr; i++)
        if (dr[a[i]]==0)
        dr[a[i]]=st[a[i]];
    dp[1][0]=calc(1,a[1],0);
    dp[1][1]=calc(1,a[1],1);
    for (i=2; i<=nr; i++)
    {
        long long d1,d2,d3,d4;
        d1=calc(st[a[i-1]],a[i],0);
        d2=calc(st[a[i-1]],a[i],1);
        d3=calc(dr[a[i-1]],a[i],0);
        d4=calc(dr[a[i-1]],a[i],1);
        dp[i][1]=min(dp[i-1][0]+d2,dp[i-1][1]+d4);
        dp[i][0]=min(dp[i-1][0]+d1,dp[i-1][1]+d3);
    }
    cout << min(dp[nr][0],dp[nr][1]) << '\n';
//    for (i=1; i<=nr; i++)
//        cout << dp[i][0] << ' ' << dp[i][1] << '\n';
//    for (i=1; i<=nr; i++)
//        cout << a[i] << ' ';
}
