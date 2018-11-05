#include <iostream>
#include <map>
#include <cstring>

using namespace std;

struct nume{char p[25];
} s[1010],a[1010];

struct cmp_str
{
   bool operator()(char const *a, char const *b)
   {
      return std::strcmp(a, b) < 0;
   }
};

map <char*, int,cmp_str> m;
map <char*, int,cmp_str>:: iterator it;

int M,n,i,nr[1010],nrs[1010],bz,vf,ans,d[1010];

int main()
{
    cin >> M;
    for (i=1; i<=M; i++)
    {
        char aux[5];
        cin >> nr[i] >> aux >> s[i].p;
        m.insert(make_pair(s[i].p,nr[i]));
    }
    cin >> n;
    vf=-1;
    for (i=1; i<=n; i++)
    {
        char aux[5];
        cin >> nrs[i] >> aux >> a[i].p;
        d[++vf]=i;
    }
    while (bz<=vf)
    {
        //it=m.find(a[d[bz]].p);
        //if (it==m.end()||(it!m.end()&&m[a[d[bz]].p]==0)
        if (m[a[d[bz]].p]==0)
            bz++;
        else
        {
            if (m[a[d[bz]].p]>=nrs[d[bz]])
            m[a[d[bz]].p]-=nrs[d[bz]],bz++;
            else
            {
                nrs[d[bz]]=m[a[d[bz]].p];
                if (bz<vf)
                    swap(d[bz],d[bz+1]);
                else
                {
                    cout << ++ans;
                    return 0;
                }
            }
        }
        ans++;
    }
    cout << ans << '\n';
}
