#include <iostream>
#include <queue>

using namespace std;

int n,k,e[110],c[110][110],i,j,tc;
int x,y,z;
int minim[110],nrh;
bool esp[110],use[110];

struct oras
{
    int x,y,cost;
};

oras h[10009];

void inserare(oras a)
{
    h[++nrh]=a;
    int ind=nrh;
    while (ind>1)
        if (a.cost<h[ind/2].cost)
            swap(h[ind],h[ind/2]),ind/=2;
        else ind=1;
}

void eliminare()
{
    h[1]=h[nrh];
    nrh--;
    int ind=1;
    while (ind*2<=nrh)
    {
        int f=ind*2;
        if (f+1<=nrh&&h[f].cost>h[f+1].cost)
            f++;
        if (h[f].cost<h[ind].cost)
        {
            swap(h[f],h[ind]);
            ind=f;
        }
        else return;
    }
}

int main()
{
    cin>>n>>k;
    for (i=1; i<=k; i++)
        cin>>e[i],esp[e[i]]=1;
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
            cin>>c[i][j];
    for (i=1; i<=k; i++)
        for (j=1; j<=n; j++)
            if (!esp[j])
            {
                oras a;
                a.x=e[i];
                a.y=j;
                a.cost=c[e[i]][j];
                inserare(a);
            }
    int nrm=k;
    while (nrm<n)
    {
        while (use[h[1].y])
            eliminare();
        oras a=h[1];
        eliminare();
        use[a.x]=1;
        nrm++;
        for (j=1; j<=n; j++)
            if (j!=a.y&&!use[j]&&!esp[j])
            {
                oras b;
                b.x=a.y;
                b.y=j;
                b.cost=c[a.y][j];
                inserare(b);
            }
        tc+=a.cost;
        use[a.y]=1;
    }
    cout<<tc<<'\n';
    return 0;
}
