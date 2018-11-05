#include <iostream>

using namespace std;

struct matrice
{
    int mat[3][3];
} a;
int n,k;

matrice inmultire(matrice a, matrice b)
{
    matrice rez;
    rez.mat[1][1]=a.mat[1][1]*b.mat[1][1]+a.mat[1][2]*b.mat[2][1];
    rez.mat[1][2]=a.mat[1][1]*b.mat[1][2]+a.mat[1][2]*b.mat[2][2];
    rez.mat[2][1]=a.mat[2][1]*b.mat[1][1]+a.mat[2][2]*b.mat[2][1];
    rez.mat[2][2]=a.mat[2][1]*b.mat[1][2]+a.mat[2][2]*b.mat[2][2];
    return rez;
}

matrice explog(matrice a, int x)
{
    if (x==1) return a;
    matrice k=explog(a,x/2);
    if (x%2) return inmultire(inmultire(k,k),a);
    return inmultire(k,k);
}

int main()
{
    cin>>n>>k;
    if (n==0) cout<<1;
    else if (n==1) cout<<k-1;
    else
    {
        a.mat[1][1]=0;
        a.mat[1][2]=a.mat[2][2]=k-1;
        a.mat[2][1]=1;
        matrice rez=explog(a,n-1);
        int ans=rez.mat[1][2]+rez.mat[2][2]*(k-1);
        cout<<ans;
    }
}
