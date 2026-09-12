#include<iostream>
using namespace std;

const int N = 25;
int gox[2] = {-1,0};    //y
int goy[2] = {0,-1};    //x

int mx[8] = {-2,-1,1,2,2,1,-1,-2};
int my[8] = {-1,-2,-2,-1,1,2,2,1};

long long f[N][N];    //i行j列 i+goy j+gox
int a[N][N];

int n,m;
int main()
{
    int tx,ty;
    cin>>n>>m>>tx>>ty;

    a[tx][ty] = 1;
    for(int i=0;i<=7;i++)
    {
        int nox = tx + my[i];
        int noy = ty + mx[i];
        if(nox>=0 && noy>=0 && nox<=n && noy<=m)a[nox][noy] = 1;
    }

    f[0][0] = 1;

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            int nox=0,noy=0;
            for(int x=0;x<=1;x++)
            {
                nox = i+goy[x];
                noy = j+gox[x];
                if(nox>=0 && noy>=0 && a[nox][noy]!=1)
                {
                    f[i][j] += f[nox][noy];
                }
            }
        }
    }

    cout<<f[n][m];
    
}