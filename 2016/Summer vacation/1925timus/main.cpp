#include <iostream>

using namespace std;

int n,i,s1,s2,k;

int main()
{
    cin>>n>>k;
    for (i=1; i<=n; i++)
    {
        int x,y;
        cin>>x>>y;
        s1+=x-2;
        s2+=y;
    }
    if (s1+k-2-s2>=0)
        cout<<s1+k-2-s2;
    else cout<<"Big Bang!";
    cout<<'\n';
}
