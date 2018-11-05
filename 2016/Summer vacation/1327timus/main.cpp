#include <iostream>

using namespace std;

int a,b;

int main()
{
    cin>>a>>b;
    a+=1-a%2;
    if (a>b)
        cout<<0<<'\n';
    else
        cout<<(b-a)/2+1<<endl;
    return 0;
}
