#include <iostream>

using namespace std;

int n,i,a[1000],aux;

void inmultire(int a[], int x)
{
    int t=0,i;
    for (i=1; i<=a[0]; i++)
    {
        a[i]=a[i]*x+t;
        t=a[i]/10;
        a[i]%=10;
    }
    while (t)
    {
        a[++a[0]]=t%10;
        t/=10;
    }
}

int main()
{
    cin>>n;
    if (n==4||n==1)
        cout<<n;
    else
    {
        aux=n%3;
        a[0]=1;
        a[1]=1;
        if (aux!=1)
        {
            for (i=1; i<=n/3; i++)
                inmultire(a,3);
            if (aux)
                inmultire(a,aux);
        }
        else
        {
            for (i=1; i<n/3; i++)
                inmultire(a,3);
            inmultire(a,4);
        }
        for (i=a[0]; i; i--)
            cout<<a[i];
    }
}
