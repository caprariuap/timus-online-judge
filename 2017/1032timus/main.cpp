#include <iostream>

using namespace std;

int n,i,j,sum[10010],a[10010],poz[10010];

int main()
{
    cin >> n;
    for (i=1; i<=n; i++)
    {
        cin >> a[i];
        sum[i]=(sum[i-1]+a[i])%n;
        if (sum[i]==0)
        {
            cout << i << '\n';
            for (j=1; j<=i; j++)
                cout << a[j] << '\n';
            return 0;
        }
        if (poz[sum[i]]!=0)
        {
            int x=poz[sum[i]];
            cout << i-x << '\n';
            for (j=x+1; j<=i; j++)
                cout << a[j] << '\n';
            return 0;
        }
        else
            poz[sum[i]]=i;
    }
}
