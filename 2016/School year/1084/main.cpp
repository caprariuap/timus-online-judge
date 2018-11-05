#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double n,R,ans,pi;

int main()
{
    cin>>n>>R;
    pi=3.14159265358979323846;
    if (R<=n/2)
        ans=pi*R*R;
    else
        if (R<=n*sqrt(2)/2)
        {
            double theta=2*acos(n/(2*R));
            ans=pi*R*R-4*R*R*(theta-sin(theta))/2;
        }
        else
            ans=n*n;
    cout<<setprecision(3)<<fixed<<ans;
    return 0;
}
