#include <iostream>
#include <cstring>

using namespace std;

int n,i,j;
bool use[1000000];
char s[100010];

int main()
{
    cin >> s;
    n=strlen(s);
    for (i=0; i<n; i++)
    {
        int nr=0;
        for (j=i; j<=min(i+5,n); j++)
        {
            nr=nr*10+s[j]-'0';
            use[nr]=1;
        }
    }
    for (i=1; i<=1000000; i++)
        if (!use[i])
        {
            cout << i << '\n';
            return 0;
        }
}
