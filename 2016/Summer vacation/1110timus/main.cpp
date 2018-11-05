#include <iostream>

using namespace std;

int n,m,y;

int explog(int x,int p)
{
    if (p==1) return x;
    int k=explog(x,p/2)%m;
    if (p%2)
        return ((k*k)%m*x)%m;
    else return k*k%m;
}

bool ok=0;

int main()
{
    cin>>n>>m>>y;
    for (int i=0; i<m; i++)
        if (explog(i,n)%m==y)
            ok=1,cout<<i<<' ';
    if (!ok) cout<<"-1";
    cout<<'\n';
}
