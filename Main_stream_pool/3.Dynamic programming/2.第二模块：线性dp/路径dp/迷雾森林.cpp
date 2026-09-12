#include<iostream>
using namespace std;

const int N = 3e3 + 10;
int a[N][N];
int f[N][N];
int n,m;

int gox[2] = {1,0};
int goy[2] = {0,-1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        cin>>a[i][j];
    }
    
    f[n][1] = 1;
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=m;j++)
        {
            int nox=0,noy=0;
            for(int x=0;x<=1;x++)
            {
                nox = i+gox[x];
                noy = j+goy[x];
                if(nox<=n && noy>=1 && a[nox][noy]!=1)
                {
                    f[i][j]+=f[nox][noy]%2333;
                }
            }  
        }
    }
    
    cout<<f[1][m]%2333;
}