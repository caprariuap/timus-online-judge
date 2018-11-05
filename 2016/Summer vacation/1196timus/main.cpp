#include <iostream>
#include <cstdio>

using namespace std;
long long n,m,i,a[15010],nr;
bool used[15010];

bool cb(int x)
{
    int p=1;int u=n;
    bool gasit=0;
    int poz;
    while (p<=u&&!gasit)
    {
        int m=(p+u)/2;
        if (a[m]==x)
            return 1;
        else if (a[m]<x) p=m+1;
        else u=m-1;
    }
    return 0;
}

int main()
{
    cin>>n;
    for (i=1; i<=n; i++)
        scanf("%d",&a[i]);
    cin>>m;
    for (i=1; i<=m; i++)
    {int x;
    scanf("%d",&x);
        if (cb(x)==1)
            nr++;
    }
    cout<<nr;
}
