#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int n;
double pi=3.141592;

int main()
{
    cin>>n;
    double x=1.0/cos(pi*(n-2)/(2*n))+1.0;
    if (n==1)
        x=1;
    cout<<fixed<<setprecision(6)<<x;
    return 0;
}
