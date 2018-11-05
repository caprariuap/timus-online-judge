#include <iostream>
#define max(a,b) a>b ? a : b

using namespace std;

int n,i;
double sum,a[200];

int main()
{
    cin>>n;
    for (i=1; i<=n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    double drank=sum/(n+1);
    for (i=1; i<=n; i++)
        a[i]=max(a[i]-drank,0);
    sum=0;
    for (i=1; i<=n; i++)
        sum+=a[i];
    for (i=1; i<=n; i++)
    if (a[i]>0)
    cout<<int(a[i]*100/sum+0.0001)<<' ';
    else cout<<0<<' ';
}
