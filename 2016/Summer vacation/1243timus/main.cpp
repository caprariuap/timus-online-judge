#include <iostream>
#include <cstring>

using namespace std;

char s[60];
int v[60];

int rest(int x)
{
    int r=0;
    for (int i=v[0]; i; i--)
    {
        r=r*10+v[i];
        v[i]=r/x;
        r%=x;
    }
    while (!v[v[0]]&&v[0]>1) v[0]--;
    return r;
}

int main()
{
    cin>>s;
    v[0]=strlen(s);
    for (int i=v[0]-1; i>=0; i--)
        v[v[0]-i]=s[i]-'0';
    cout<<rest(7);
    cout<<'\n';
}
