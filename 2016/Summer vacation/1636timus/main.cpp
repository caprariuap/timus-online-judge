#include <iostream>

using namespace std;

int t1,t2;
int r2,i;

int main()
{
    cin>>t1>>t2;
    for (i=1; i<=10; i++)
    {
        int x;
        cin>>x;
        r2+=x;
    }
    if (t2-r2*20<t1)
        cout<<"Dirty debug :(";
    else
        cout<<"No chance.";
    cout<<'\n';
}
