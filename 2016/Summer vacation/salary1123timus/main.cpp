#include <iostream>
#include <cstring>

using namespace std;
int num[2010],n,i,j,mid,ls;
char s[2010];

int main()
{cin.getline(s,2010,'\n');
n=strlen(s);
for (i=0; i<n; i++)
    num[i]=s[i]-'0';
mid=n/2;
int ok=1;
for (i=0; i<n&&ok; i++)
    if (num[i]!=num[n-i])
        ok=0;
if (ok)
    cout<<s;
else
{ls=0;
i=mid-1;
j=mid+n%2;
while (i>=0&&num[i]==num[j])
    i--,j++;
if (num[i]<num[j])
    ls=1;
while (i>=0)
num[j++]=num[i--];
if (ls)
{int c=1;
i=mid-1;
if (n%2)
{num[mid]+=c;
c=num[mid]/10;
num[mid]%=10;
j=mid+1;
}
else
    j=mid;
while (i>=0)
{num[i]+=c;
c=num[i]/10;
num[i]%=10;
num[j++]=num[i--];
}
}
for (i=0; i<n; i++)
    cout<<num[i];
}
}
