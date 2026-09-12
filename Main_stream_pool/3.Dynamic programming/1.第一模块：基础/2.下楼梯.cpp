#include<iostream>
using namespace std;

int n;

//滑动窗口空间优化

int main()
{
    cin>>n;
    long long a = 1,b = 2,c = 4;
    long long t = 0;
    for(int i=4;i<=n;i++)
    {
        t = a+b+c;
        a = b;
        b = c;
        c = t;
    }
    cout<<t;
}