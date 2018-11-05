#include <iostream>

using namespace std;

char c[10];
int n;
int a[10],b[10];

void adunare(int a[],int x)
{
    a[1]+=x;
    int t=a[1]/10;
    a[1]%=10;
    int i=2;
    while (t)
    {
        a[i]+=t;
        t=a[i]/10;
        a[i]%=10;
        i++;
    }
}

void scadere(int a[],int x)
{
    int t=0;
    a[1]-=x;
    if (a[1]<0) a[1]+=10,t=1;
    int i=2;
    while (t)
    {
        a[i]-=t;
        t=0;
        if (a[i]<0) a[i]+=10,t=1;
        i++;
    }
}

bool verifica(int a[])
{
    return (a[1]+a[2]+a[3]==a[4]+a[5]+a[6]);
}

int main()
{
    cin>>c;
    for (int i=0; i<6; i++)
        a[6-i]=b[6-i]=c[i]-'0';
    a[0]=b[0]=6;
    adunare(a,1);
    scadere(b,1);
    if (verifica(a)||verifica(b))
        cout<<"Yes";
    else cout<<"No";
    cout<<'\n';
}
