#include <cstdio>
#include <cmath>

using namespace std;

long long a,b,n,x,y,i,j,rn,minim;
bool swapped;

void solve()
{
    swapped=0;
    minim=n;
    if (a<b) {
        long long aux=a;
        a=b;
        b=aux;
        swapped=1;
    }
    rn=sqrt(n);
    if (a>=rn)
    {
        for (i=0; a*i<=n; i++)
            if ((n-a*i)%b<minim)
        {
            minim=(n-a*i)%b;
            x=i;
            y=(n-a*i)/b;
        }
    }
    else
    {
        long long cs=0;
        long long xx;
        xx=0;
        while (cs+a*b<=n)
            cs=cs+a*b,xx+=b;
        cs=cs-a*b;
        xx-=b;
        for (i=0; a*i<=n-cs; i++)
            if ((n-cs-a*i)%b<minim)
        {
            minim=(n-cs-a*i)%b;
            x=i;
            y=(n-cs-a*i)/b;
        }
        x+=xx;
    }
    if (swapped)
    {
        long long aux=x;
        x=y;
        y=aux;
    }
}

int main()
{
    scanf("%lld%lld%lld",&a,&b,&n);
    solve();
    printf("%lld %lld",x,y);
}
/*
n%(a*x+b*y)=minim
*/
