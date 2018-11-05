#include <iostream>
#include <vector>

using namespace std;

vector <long long> v[1010],from[1010];
long long n,i,nrc,postordine[1010],util[1010],nr,a[1010],cmmdc,cmmmc;
bool use[1010];

void sortt(int x)
{
    use[x]=1;
    for (int i=0; i<v[x].size(); i++)
        if (!use[v[x][i]])
        sortt(v[x][i]);
    postordine[++nr]=x;
}

void dfs(int x)
{
    use[x]=0;
    util[nrc]++;
    for (int i=0; i<from[x].size(); i++)
        if (use[from[x][i]])
            dfs(from[x][i]);
}

int __gcd(int a, int b)
{
    int r;
    while (b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    cin >> n;
    for (i=1; i<=n; i++)
    {
        cin >> a[i];
        v[i].push_back(a[i]);
        from[a[i]].push_back(i);
    }
    for (i=1; i<=n; i++)
        if (!use[i])
        sortt(i);
    for (i=n; i; i--)
        if (use[postordine[i]])
        {
            nrc++;
            dfs(postordine[i]);
        }
    cmmdc=util[1];
    cmmmc=util[1];
    for (i=2; i<=nrc; i++)
        {
            cmmdc=__gcd(cmmmc,util[i]);
            cmmmc=cmmmc*util[i]/cmmdc;
        }
    cout << cmmmc << '\n';
}
