#include<iostream>
using namespace std;

const int N = 1e5;
int f[N];

int fib( int a )
{
    f[0] = 0;
    f[1] = 1;
    f[2] = 1;

    for(int i=2;i<=a;i++)
    {
        f[i] = f[i-1] + f[i-2]; 
    }

    return f[a];
}


int main()
{
    cout<<f[4];
}