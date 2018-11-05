#include <cstdio>
#include <queue>
#include <vector>
#define nmax 510

using namespace std;

vector <int> v[nmax],cost[nmax];
int pr[nmax],n,m,i;
bool inH[nmax];

class cmp
{
public:
    bool operator()(int A, int B)
    {
        return pr[A]<pr[B];
    }
};

queue <int> H;

int main()
{
    scanf("%d%d",&n,&m);
    for (i=1; i<=m; i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v[a].push_back(b);
        cost[a].push_back(c);
    }
    int S,F;
    scanf("%d%d",&S,&F);
    H.push(S);
    inH[S]=1;
    while (!H.empty())
    {
        int nod=H.front();
        inH[nod]=0;
        H.pop();
        for (i=0; i<v[nod].size(); i++)
        {
            int vecin=v[nod][i];
            if (pr[vecin]<pr[nod]+cost[nod][i])
            {
                pr[vecin]=pr[nod]+cost[nod][i];
                if (!inH[vecin])
                H.push(vecin);
                inH[vecin]=1;
            }
        }
    }
    if (pr[F]==0)
    {
        printf("No solution\n");
        return 0;
    }
    printf("%d\n",pr[F]);
}
