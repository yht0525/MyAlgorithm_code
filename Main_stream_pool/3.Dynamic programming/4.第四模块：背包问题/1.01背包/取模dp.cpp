#include<iostream>
using namespace std;

const int N = 2e3+10;
int n,F;
int f[N][N];
int a[N];

int main()
{
    cin>>n>>F;

    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        a[i] = t%F;
    }

    f[0][0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=F-1;j++)
        {
            f[i][j] = (f[i-1][j] + f[i-1][((j-a[i])%F+F)%F])%100000000;         //无法正常空间优化！！！（递推的时候要用左右的值）
        }
    }
    cout<<(f[n][0]-1);
}