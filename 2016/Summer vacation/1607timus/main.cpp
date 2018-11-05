#include <iostream>

using namespace std;

int a,b,c,d;

int main()
{
    cin>>a>>b>>c>>d;
    while (a<c)
    {
        if (a+b>c)
        {
            a=c;
            break;
        }
        a+=b;
        c-=d;
    }
    cout<<a;
}
