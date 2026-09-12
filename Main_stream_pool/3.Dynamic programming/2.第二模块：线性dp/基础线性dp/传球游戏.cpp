#include<iostream>
using namespace std;

const int N = 35;
int m,n;
int f[N][N];    //表示第i次的球在第j个同学手里的方案

int main()
{
    cin>>n>>m;
    
    f[0][1] = 1;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j == 1)
            {
                f[i][j] = f[i-1][n] + f[i-1][2];
            }
            else if(j == n)
            {
                f[i][j] = f[i-1][1] + f[i-1][n-1];
            }
            else
            {
                f[i][j] = f[i-1][j-1] + f[i-1][j+1];
            }
        }
    }
    cout<<f[m][1];
}