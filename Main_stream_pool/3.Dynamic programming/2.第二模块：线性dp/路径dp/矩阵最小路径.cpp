#include<iostream>
using namespace std;

const int N = 505;
int f[N][N];
int a[N][N];
int gox[2] = {-1,0};
int goy[2] = {0,-1};
int n,m;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        if(i==1 && j==1)
        {
            f[1][1] = a[1][1];
            continue;
        }
        int ret = 100000;
        for(int x=0;x<=1;x++)
        {
            int nox = i+gox[x],noy = j+goy[x];
            if(nox>=1 && nox<=n && noy>=1 && noy<=m)
            {
                ret = min(ret,f[nox][noy]);
            }
        }
        f[i][j] = ret+a[i][j];
    }

    cout<<f[n][m];
}