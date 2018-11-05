#include <iostream>

using namespace std;

int n,k,a[100010],i;
int unused,survived;

int main()
{cin>>n>>k;
for (i=1; i<=n; i++)
    cin>>a[i];
for (i=1; i<=n; i++)
    if (a[i]>k) unused+=a[i]-k;
else survived+=k-a[i];
cout<<unused<<' '<<survived;
}
