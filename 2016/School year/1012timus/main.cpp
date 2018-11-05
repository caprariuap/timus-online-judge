#include <iostream>

using namespace std;

struct matrice
{
    long long mat[3][3][3000];
} a;
long long n,k,K[3000],i,j,ans[3000];

void adunare(long long a[], long long b[])
{
    int i, T=0;
    if (b[0]>a[0])
    {
        for (i=a[0]+1; i<=b[0]; i++)
            a[i]=0;
        a[0]=b[0];
    }
    else for (i=b[0]+1; i<=a[0]; i++)
        b[i]=0;
    for (i=1; i<=a[0]; i++)
    {
        a[i]+=b[i]+T;
        T=a[i]/10;
        a[i]%=10;
    }
    if (T)
        a[++a[0]]=T;
}

void inm(long long a[], long long x)
{
    int i;
    long long T=0;
    for (i=1; i<=a[0]; i++)
    {
        a[i]=a[i]*x+T;
        T=a[i]/10;
        a[i]%=10;
    }
    while (T)
        a[++a[0]]=T%10,T/=10;
}

void inmultirem(long long a[], long long b[], long long c[])
{
    int i,j;
    long long T=0;
    c[0]=a[0]+b[0]-1;
    for (i=1; i<=a[0]+b[0]; i++) c[i]=0;
    for (i=1; i<=a[0]; i++)
        for (j=1; j<=b[0]; j++)
        c[i+j-1]+=a[i]*b[j];
    for (i=1; i<=c[0]; i++)
    {
        c[i]+=T;
        T=c[i]/10;
        c[i]%=10;
    }
    if (T) c[++c[0]]=T;
}

matrice inmultire(matrice a, matrice b)
{
    matrice rez,aux;

    inmultirem(a.mat[1][1],b.mat[1][1],rez.mat[1][1]);
    inmultirem(a.mat[1][2],b.mat[2][1],aux.mat[1][1]);
    adunare(rez.mat[1][1],aux.mat[1][1]);

    inmultirem(a.mat[1][1],b.mat[1][2],rez.mat[1][2]);
    inmultirem(a.mat[1][2],b.mat[2][2],aux.mat[1][2]);
    adunare(rez.mat[1][2],aux.mat[1][2]);

    inmultirem(a.mat[2][1],b.mat[1][1],rez.mat[2][1]);
    inmultirem(a.mat[2][2],b.mat[2][1],aux.mat[2][1]);
    adunare(rez.mat[2][1],aux.mat[2][1]);

    inmultirem(a.mat[2][1],b.mat[1][2],rez.mat[2][2]);
    inmultirem(a.mat[2][2],b.mat[2][2],aux.mat[2][2]);
    adunare(rez.mat[2][2],aux.mat[2][2]);
//    rez.mat[1][1]=a.mat[1][1]*b.mat[1][1]+a.mat[1][2]*b.mat[2][1];
//    rez.mat[1][2]=a.mat[1][1]*b.mat[1][2]+a.mat[1][2]*b.mat[2][2];
//    rez.mat[2][1]=a.mat[2][1]*b.mat[1][1]+a.mat[2][2]*b.mat[2][1];
//    rez.mat[2][2]=a.mat[2][1]*b.mat[1][2]+a.mat[2][2]*b.mat[2][2];
    return rez;
}

matrice explog(matrice a, long long x)
{
    if (x==1) return a;
    matrice k=explog(a,x/2);
    if (x%2) return inmultire(inmultire(k,k),a);
    return inmultire(k,k);
}

int main()
{
    cin>>n>>k;
    long long ck=k-1;
    while (ck)
        K[++K[0]]=ck%10,ck/=10;
    if (n==0) cout<<1;
    else if (n==1) cout<<k-1;
    else
    {
        a.mat[1][1][0]=a.mat[1][1][1]=0;
        for (i=0; i<=K[0]; i++)
        a.mat[1][2][i]=a.mat[2][2][i]=K[i];
        a.mat[2][1][0]=a.mat[2][1][1]=1;
        matrice rez=explog(a,n-1);
        adunare(ans,rez.mat[1][2]);
        inm(rez.mat[2][2],k-1);
        adunare(ans,rez.mat[2][2]);
        for (i=ans[0]; i; i--)
            cout<<ans[i];
    }
}
