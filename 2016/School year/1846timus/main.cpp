#include <cstdio>
#include <map>

using namespace std;

int q,a,i,arbint[1000000],nr;
char c[2];

map <int,int> fr,poz;

int cmmdc(int a,int b)
{
    if (a==0)
        return b;
    if (b==0)
        return a;
    int r;
    while (b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

void update(int nod, int st, int dr, int ind, int val)
{
    if (st==dr)
    {
        arbint[nod]=arbint[nod]+val;
        return ;
    }
    int mij=(st+dr)/2;
    if (ind<=mij)
        update(2*nod,st,mij,ind,val);
    else
        update(2*nod+1,mij+1,dr,ind,val);
    arbint[nod]=cmmdc(arbint[2*nod],arbint[2*nod+1]);
}

int main()
{
    scanf("%d",&q);
    for (i=1; i<=q; i++)
    {
        scanf("%s%d",&c,&a);
        if (c[0]=='+')
        {
            fr[a]++;
            if (fr[a]==1)
            {
                if (poz[a]==0)
                {
                    nr++;
                    poz[a]=nr;
                }
                update(1,1,q,poz[a],a);
            }
        }
        else
        {
            fr[a]--;
            if (fr[a]==0)
            {
                update(1,1,q,poz[a],-a);
            }
        }
        printf("%d\n",arbint[1]==0 ? 1 : arbint[1]);
    }
}
