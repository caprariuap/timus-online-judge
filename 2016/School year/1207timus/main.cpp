#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct punct{
    long long x,y,poz;
} a[100010];

long long n,minim,ans1,ans2,i,xo,yo;

double cos(punct A)
{
    long long X=A.x-xo;
    long long Y=A.y-yo;
    double rad=sqrt(X*X+Y*Y),rez;
    rez=X/rad;
    return rez;
}

bool cmp(punct a, punct b)
{
    return cos(a)>cos(b);
}

int main ()
{
    scanf("%lld",&n);
    scanf("%lld%lld",&a[1].x,&a[1].y);
    a[1].poz=1;
    minim=a[1].y;xo=a[1].x;yo=a[1].y;
    ans1=1;
    for (i=2; i<=n; i++)
    {
        scanf("%lld%lld",&a[i].x,&a[i].y);
        a[i].poz=i;
        if (a[i].y<minim)
        {
            minim=a[i].y;
            ans1=i;
            xo=a[i].x;
            yo=a[i].y;
        }
    }
    swap(a[1],a[ans1]);
    sort(a+2,a+n+1,cmp);
    ans2=a[n/2+1].poz;
    printf("%lld %lld\n",ans1,ans2);
}
