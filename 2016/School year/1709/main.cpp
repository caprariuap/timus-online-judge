#include <iostream>

using namespace std;

long a[110][110],b[110][110],i,j,n,d,A,nrc,rad[110];
bool use[110];

void dfs(long long x)
{
    use[x]=1;
    for (long long i=1; i<=n; i++)
        if (a[x][i]==1&&!use[i])
        b[x][i]=b[i][x]=nrc,dfs(i);
}

int main()
{
    cin>>n;
    cin>>d>>A;
    for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                {
                    char c;
                    cin>>c;
                    a[i][j]=c-'0';
                }
    for (i=1; i<=n; i++)
        if (!use[i])
        {
            nrc++;
            rad[nrc]=i;
            dfs(i);
        }
    for (i=2; i<=nrc; i++)
        b[1][rad[i]]=b[rad[i]][1]=-A;
    long long ANS=0;
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
            if (b[i][j]==0&&a[i][j]!=0)
            ANS+=d;
        else
        {
            if (b[i][j]==-A)
                ANS+=A;
        }
    }
    cout<<ANS/2<<'\n';
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
            if (b[i][j]==0&&a[i][j]!=0)
            cout<<'d';
        else
        {
            if (b[i][j]==-A)
                cout<<'a';
            else cout<<0;
        }
        cout<<'\n';
    }
}
