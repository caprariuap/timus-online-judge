#include <iostream>
#include <cstring>

using namespace std;

char s[1001][3];
int n,i;
char c;

int main()
{
    cin>>n;
    for (i=1; i<=n; i++)
        cin>>s[i];
    cin>>c;
    for (i=1; i<=n; i++)
        if (s[i][0]==c)
            cout<<s[i]<<'\n';
}
