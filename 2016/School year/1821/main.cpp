#include <iostream>
#include <cstring>

using namespace std;

char ans[101][21],name[101][21],number[300];
int time[101],n,i,minim,nr,j,unadjtime[101];

int takenumber()
{
    int N,poz,nmr;
    N=poz=nmr=0;
    while (number[poz]!=':')
    {
        nmr=nmr*10+number[poz]-'0';
        ++poz;
    }
    nmr=nmr*600;
    poz++;
    int nmr2=0;
    while (number[poz]!='.')
    {
        nmr2=nmr2*10+number[poz]-'0';
        ++poz;
    }
    nmr2*=10;
    nmr+=nmr2;
    poz++;
    nmr=nmr+number[poz]-'0';
    return nmr;
}

int main()
{
    minim=100000;
    cin>>n;
    for (i=1; i<=n; i++)
    {
        cin>>name[i];
        cin>>number;
        time[i]=takenumber();
        unadjtime[i]=time[i]+300*(i-1);
    }
    for (i=1; i<n; i++)
        for (j=i+1; j<=n; j++)
            if (unadjtime[i]>unadjtime[j])
            {
                char aux[21];
                strcpy(aux,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],aux);
                swap(time[i],time[j]);
                swap(unadjtime[i],unadjtime[j]);
            }
    for (i=1; i<=n; i++)
    {
        if (time[i]<minim)
        {
            nr++;
            strcpy(ans[nr],name[i]);
            minim=time[i];
        }
    }
    for (i=1; i<nr; i++)
        for (j=i+1; j<=nr; j++)
            if (strcmp(ans[i],ans[j])>0)
            {
                char aux[21];
                strcpy(aux,ans[i]);
                strcpy(ans[i],ans[j]);
                strcpy(ans[j],aux);
            }
    cout<<nr<<'\n';
    for (i=1; i<=nr; i++)
        cout<<ans[i]<<'\n';
    return 0;
}
