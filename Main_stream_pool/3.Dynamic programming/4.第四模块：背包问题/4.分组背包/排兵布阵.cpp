#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e2+10,M = 2e4+10;
int f[N][M];
int a[N][N];

int s,n,m;

int main()
{
    cin>>s>>n>>m;

    for(int i=1;i<=s;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int t;
            cin>>t;
            a[j][i] = 2*t+1;
        }
    }

    for(int i=1;i<=n;i++)
    {
        sort(a[i]+1,a[i]+s+1);  //排序可省去遍历的时间
    }

    for(int i=1;i<=n;i++)        //第i组  a[i][j]
    {
        for(int j=1;j<=m;j++)
        {
            f[i][j] = f[i-1][j];
            for(int x=1;x<=s;x++)
            {
                if(j>=a[i][x]){
                    f[i][j] = max(f[i][j],f[i-1][j-a[i][x]]+x*i);
                }
                else{
                    break;
                }
            }
        }
    }

    cout<<f[n][m];
}