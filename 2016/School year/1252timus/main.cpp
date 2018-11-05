#include <iostream>
#include <algorithm>
#define nmax 130010

using namespace std;

struct pct{
int poz,val;} a[nmax];

int n,i,ans1,ans2;

int gcd(int a, int b)
{
    int c;
    while (b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

class cmp1
{
    public :
    bool operator()(const pct &a, const pct &b)
    {
        return a.val<=b.val;
    }
};

int abs(int a)
{
    if (a<0)
        return -a;
    return a;
}

int main()
{
    cin >> n;
    for (i=1; i<=n; i++)
        cin >> a[i].val,a[i].poz=i;
    sort(a+1,a+n+1,cmp1());
    ans1=abs(a[1].poz-1);
    for (i=2; i<=n; i++)
        ans1=gcd(ans1,abs(a[i].poz-i));
    ans2=abs(n-a[1].poz+1-1);
    for (i=2; i<=n; i++)
        ans2=gcd(ans2,abs(n-a[i].poz+1-i));
    if (ans1>0) ans1--;
    else ans1=n-1;
    if (ans2>0) ans2--;
    else ans2=n-1;
    if (ans1<ans2)
        cout << ans2;
    else
        cout << ans1;
    cout << '\n';
}
