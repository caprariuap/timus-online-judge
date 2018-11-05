#include <iostream>
#include <fstream>

using namespace std;

//ofstream fout("debug.out");

struct matrice
{
    long long mat[3][3][50];
} a;
long long ans[50];
unsigned long long n,k,i,j,M;

void iniat(long long a[], unsigned long long k)
{
    a[0]=0;
    while (k)
        a[++a[0]]=k%10,k/=10;
}

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

void inm(long long a[], unsigned long long x)
{
    int i;
    unsigned long long T=0;
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
    unsigned long long T=0;
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

unsigned long long rest(long long a[], unsigned long long M)
{
    unsigned long long i,R=0;
    for (i=a[0]; i; i--)
        R=(R*10+a[i])%M;
    return R;
}

matrice inmultire(matrice a, matrice b)
{
    matrice rez,aux;

    inmultirem(a.mat[1][1],b.mat[1][1],rez.mat[1][1]);
    inmultirem(a.mat[1][2],b.mat[2][1],aux.mat[1][1]);
    adunare(rez.mat[1][1],aux.mat[1][1]);
    unsigned long long auxx=rest(rez.mat[1][1],M);
    iniat(rez.mat[1][1],auxx);

    inmultirem(a.mat[1][1],b.mat[1][2],rez.mat[1][2]);
    inmultirem(a.mat[1][2],b.mat[2][2],aux.mat[1][2]);
    adunare(rez.mat[1][2],aux.mat[1][2]);
    auxx=rest(rez.mat[1][2],M);
    iniat(rez.mat[1][2],auxx);


    inmultirem(a.mat[2][1],b.mat[1][1],rez.mat[2][1]);
    inmultirem(a.mat[2][2],b.mat[2][1],aux.mat[2][1]);
    adunare(rez.mat[2][1],aux.mat[2][1]);
    auxx=rest(rez.mat[2][1],M);
    iniat(rez.mat[2][1],auxx);


    inmultirem(a.mat[2][1],b.mat[1][2],rez.mat[2][2]);
    inmultirem(a.mat[2][2],b.mat[2][2],aux.mat[2][2]);
    adunare(rez.mat[2][2],aux.mat[2][2]);
    auxx=rest(rez.mat[2][2],M);
    iniat(rez.mat[2][2],auxx);

//    rez.mat[1][1]=a.mat[1][1]*b.mat[1][1]+a.mat[1][2]*b.mat[2][1];
//    rez.mat[1][2]=a.mat[1][1]*b.mat[1][2]+a.mat[1][2]*b.mat[2][2];
//    rez.mat[2][1]=a.mat[2][1]*b.mat[1][1]+a.mat[2][2]*b.mat[2][1];
//    rez.mat[2][2]=a.mat[2][1]*b.mat[1][2]+a.mat[2][2]*b.mat[2][2];
    return rez;
}

matrice explog(matrice a, unsigned long long x)
{
    if (x==1) return a;
    matrice k=explog(a,x/2);
    int i,j;
    for (i=1; i<=2; i++)
        for (j=1; j<=2; j++)
        {
            unsigned long long auxx=rest(k.mat[i][j],M);
            iniat(k.mat[i][j],auxx);
//            for (int kk=k.mat[i][j][0]; kk; kk--)
//                fout<<k.mat[i][j][kk];fout<<"WTF"<<'\n';
        }
    if (x%2) return inmultire(inmultire(k,k),a);
    return inmultire(k,k);
}

int main()
{
    cin>>n>>k>>M;
    a.mat[1][1][0]=1;
    a.mat[1][1][1]=0;
    iniat(a.mat[1][2],(k-1)%M);
    iniat(a.mat[2][2],(k-1)%M);
    a.mat[2][1][0]=a.mat[2][1][1]=1;
    matrice rez=explog(a,n-1);

    unsigned long long auxx=rest(rez.mat[1][2],M);
    iniat(rez.mat[1][2],auxx);

    for (i=0; i<=rez.mat[1][2][0]; i++)
        ans[i]=rez.mat[1][2][i];
    inm(rez.mat[2][2],(k-1)%M);

    auxx=rest(rez.mat[2][2],M);
    iniat(rez.mat[2][2],auxx);

    adunare(ans,rez.mat[2][2]);
    unsigned long long anss=rest(ans,M);
    cout<<anss<<'\n';
}
