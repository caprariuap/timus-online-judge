#include <iostream>
int n,i,j,cn,ans;
int plu=1;

using namespace std;

int main()
{
    cin>>n;
    n--;
    cn=n;
    while (cn)
    {
        cn=cn-(cn+1)/2;
        ans++;
    }
    cout<<ans<<'\n';
    plu=1;
    while (n)
    {
        cout<<(n+1)/2<<' ';
        n=n-(n+1)/2;
    }
    return 0;
}
