#include <iostream>

using namespace std;

char s[10];
int i;

int getnr(int &i)
{
    int ans=0;
    while (s[i]>='0'&&s[i]<='9')
        ans=ans*10+s[i]-'0',i++;
    return ans;
}

int main()
{
    cin>>s;
    int row=getnr(i);
    if (row<3)
    {
        if (s[i]=='A'||s[i]=='D')
            cout<<"window";
        else cout<<"aisle";
    }
    else if (row<21)
    {
        if (s[i]=='A'||s[i]=='F')
            cout<<"window";
        else cout<<"aisle";
    }
    else
    {
        if (s[i]=='A'||s[i]=='K')
            cout<<"window";
        else if (s[i]=='C'||s[i]=='D'||s[i]=='G'||s[i]=='H')
            cout<<"aisle";
        else cout<<"neither";
    }
    cout<<'\n';
}
