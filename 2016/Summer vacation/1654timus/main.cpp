#include <iostream>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

int nr;
char s[200010];
char sir[200010];

int main()
{
    char x;
    cin>>sir;
    int ind=0;
    s[nr]=sir[ind];
    while (sir[ind+1]!='\0')
    {
        x=sir[++ind];
        s[++nr]=x;
        bool ok=1;
        while (nr>0&&ok)
            if (s[nr]==s[nr-1])
            nr=nr-2;
        else ok=0;
    }
    for (int i=0; i<=nr; i++)
        cout<<s[i];cout<<'\n';
}
