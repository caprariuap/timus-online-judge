#include <iostream>
#include <cstring>

using namespace std;

int n,i,j;
char s[101][31];
char spammers[51][31];
int nos;

int main()
{
    cin>>n;
    for (i=1; i<=n; i++)
    {
        cin>>s[i];
        bool ok=1;
        for (j=1; j<i; j++)
            if (strcmp(s[i],s[j])==0)
                ok=0;
        if (!ok)
        {
            bool use=0;
            for (j=1; j<=nos; j++)
                if (strcmp(s[i],spammers[j])==0)
                use=1;
            if (!use)
                nos++,strcpy(spammers[nos],s[i]);
        }
    }
    for (i=1; i<=nos; i++)
        cout<<spammers[i]<<'\n';
}
