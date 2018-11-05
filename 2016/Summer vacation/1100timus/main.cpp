#include <iostream>
#include <algorithm>

using namespace std;

int n,m[110][150010],i,j;


int main()
{cin>>n;
for (i=1; i<=n; i++)
{int x,y;
cin>>y>>x;
m[x][++m[x][0]]=y;
}
int printed=0;
for (i=100; i>=0; i--)
    for (j=1; j<=m[i][0]; j++)
    if (printed<n)
    cout<<m[i][j]<<' '<<i<<'\n';
    else
        cout<<m[i][j]<<' '<<i;
}
