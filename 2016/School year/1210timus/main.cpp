#include <iostream>

using namespace std;

int n,i,j,nr,poz[35][35],minim[1000],k[35],ans,x;

int main()
{
    cin >> n;
    nr=1;
    poz[0][1]=1;
    minim[1]=0;
    for (i=1; i<=n; i++)
    {
        cin >> k[i];
        for (j=1; j<=k[i]; j++)
        {
            cin >> x;
            ++nr;
            minim[nr]=1000000000;
            poz[i][j]=nr;
            while (x!=0)
            {
                int y;
                cin >> y;
                if (minim[poz[i-1][x]]+y<minim[nr])
                    minim[nr]=minim[poz[i-1][x]]+y;
                cin >> x;
            }
        }
        char c;
        if (i!=n)
        cin >> c;
    }
    ans=minim[poz[n][1]];
    for (i=1; i<=k[n]; i++)
        if (minim[poz[n][i]]<ans)
            ans=minim[poz[n][i]];
    cout << ans << '\n';
}
