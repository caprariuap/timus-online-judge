#include <cstdio>
#include <algorithm>
using namespace std;

struct T{int ts,te;} t[100010];

int n,i,ans,cp;

bool comp(T a, T b)
{
   return (a.te<b.te||(a.te==b.te&&a.ts<b.ts));
}

int main()
{
    scanf("%d",&n);
    for (i=1; i<=n; i++)
        scanf("%d%d",&t[i].ts,&t[i].te);
    sort(t+1,t+n+1,comp);
    ans=1;
    cp=t[1].te;
    for (i=2; i<=n; i++)
    {
        if (t[i].ts>cp)
        {
            ans++;
            cp=t[i].te;
        }
    }
    printf("%d\n",ans);
}
