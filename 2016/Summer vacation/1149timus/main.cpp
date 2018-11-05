#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

int n,l,nr;
string a;
bool positive=0;
bool first;

void getA()
{
    if (first)
    {
        first=0;
        a="sin(1)";
        l=5;
        nr=1;
    }
    else
    {
        int i;
        nr++;
        a.erase(a.size()-nr+1,nr);
        if (positive)
            a+='+',positive=0;
        else
            a+='-',positive=1;
            a+="sin(";
        char aux[5];
        itoa(nr,aux,10);
        a+=aux;
        for (i=1; i<=nr; i++)
            a+=')';
    }
}

void getS()
{
for (int i=1; i<n; i++)
    cout<<'(';
for (int i=n; i>1; i--)
{getA();
cout<<a<<'+'<<i<<')';
}
getA();
cout<<a<<"+1";
}

int main()
{
    cin>>n;
    first=1;
    getS();
}
