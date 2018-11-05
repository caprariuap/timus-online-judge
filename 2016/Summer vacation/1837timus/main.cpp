#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

int n,i,j,nr,poz;
char nume[310][25];
int noduri[310];
char s[25]="Isenbaev";
bool ok;
int d[310];

vector <int> v[310];
queue <int> q;

int cauta(char x[])
{
    for (int i=1; i<=nr; i++)
        if (strcmp(x,nume[i])==0)
            return i;
    ++nr;
    if (strcmp(x,s)==0) poz=nr;
    strcpy(nume[nr],x);
    return nr;
}

void ver(int aa,int bb,int cc,char b[],char c[])
{
    bool oka,okb,okc;
    okb=okc=0;
    for (j=0; j<v[aa].size(); j++)
        if (strcmp(nume[v[aa][j]],b)==0)
            okb=1;
        else if (strcmp(nume[v[aa][j]],c)==0)
            okc=1;
    if (okb==0)
        v[aa].push_back(bb);
    if (okc==0)
        v[aa].push_back(cc);
}

int main()
{
    cin>>n;
    for (i=1; i<=n; i++)
    {
        char a[25],b[25],c[25];
        cin>>a>>b>>c;
        int aa=cauta(a);
        int bb=cauta(b);
        int cc=cauta(c);
        ver(aa,bb,cc,b,c);
        ver(bb,aa,cc,a,c);
        ver(cc,aa,bb,a,b);
    }
    q.push(poz);
    while (!q.empty())
    {
        int x=q.front();
        q.pop();
        for (i=0; i<v[x].size(); i++)
            if (v[x][i]!=poz)
            {
                if (d[v[x][i]]==0||d[v[x][i]]>d[x]+1)
                {
                    d[v[x][i]]=d[x]+1;
                    q.push(v[x][i]);
                }
            }
    }
    for (i=1; i<nr; i++)
        for (j=i+1; j<=nr; j++)
        if (strcmp(nume[i],nume[j])>0)
    {
        char aux[25];
        strcpy(aux,nume[j]);
        strcpy(nume[j],nume[i]);
        strcpy(nume[i],aux);
        swap(d[i],d[j]);
    }
    for (i=1; i<=nr; i++)
    {
        cout<<nume[i]<<' ';
        if (d[i]==0&&strcmp(nume[i],s)!=0) cout<<"undefined";
        else cout<<d[i];
        cout<<'\n';
    }
}
