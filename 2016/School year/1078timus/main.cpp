#include <iostream>
#include <algorithm>

using namespace std;

struct pct{
int x,y,po;} a[510];

class cmp
{
public:
    bool operator ()(const pct &a, const pct &b)
        {
            return a.y-a.x>b.y-b.x;
        }
};

int n,i,j,p[510],poz,maxim,best[510];

int main()
{
    cin >> n;
    for (i=1; i<=n; i++)
        cin >> a[i].x >> a[i].y,a[i].po=i;
    sort(a+1,a+n+1,cmp());
    for (i=1; i<=n; i++)
    {
        best[i]=1;
        p[i]=i;
        for (j=1; j<i; j++)
            if (a[j].x<a[i].x&&a[j].y>a[i].y&&best[j]+1>best[i])
                best[i]=best[j]+1,p[i]=j;
        if (best[i]>maxim)
            maxim=best[i],poz=i;
    }
    cout << maxim << '\n';
    while (p[poz]!=poz)
    {
        cout << a[poz].po << ' ';
        poz=p[poz];
    }
    cout << a[poz].po << '\n';
}
