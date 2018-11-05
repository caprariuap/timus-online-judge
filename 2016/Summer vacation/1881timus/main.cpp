#include <iostream>
#include <cstring>

using namespace std;

char s[110];
int h,w,n,i;
int ch,cw,p;

int main()
{
    cin>>h>>w>>n;
    ch=1;
    p=1;
    for (i=1; i<=n; i++)
    {
        cin>>s;
        int l=strlen(s);
        if (l+cw<=w)
            cw+=l;
        else
        {
            cw=l;
            ch++;
            if (ch>h) ch=1,p++;
        }
        if (cw<w)
        cw++;
        if (cw>w)
            cw=0,ch++;
        if (ch>h) ch=1,p++;
    }
    cout<<p;
}
