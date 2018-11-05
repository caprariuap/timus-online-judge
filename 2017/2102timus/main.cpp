#include <iostream>

using namespace std;

long long n,i,v[100000],j,nr,k;
bool prim[1100000];

int main()
{
    cin >> n;
    for (i=2; i<=1100000; i++)
        prim[i]=1;
    for (i=2; i<=1100000; i++)
    if (prim[i]==1)
    {
        nr++;
        v[nr]=i;
        for (j=i*2; j<=1100000; j+=i)
            prim[j]=0;
    }
    for (i=1; i<=nr; i++)
        if (n%v[i]==0)
        {
            while (n%v[i]==0)
                k++,n/=v[i];
        }
    if (n!=1)
    {
        k++;
    }
    if (k==20)
        cout << "Yes";
    else
        cout << "No";
    cout << '\n';
}
