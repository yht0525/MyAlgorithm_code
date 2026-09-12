#include<cstring>
#include<iostream>
using namespace std;

const int N = 3e2+10;
int n;
int f[N][N];        //在[i,j]的石子里面分的最小代价
int a[N];
int sum[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i] = sum[i-1]+a[i];        //前缀和
    }

    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++)f[i][i]=0;
    
    for(int i=n;i>=1;i--)
    {
        for(int j=i;j<=n;j++)
        {
            for(int k=i;k<j;k++)
            {
                int t = f[i][k] + f[k+1][j] + (sum[j] - sum[i-1]);
                f[i][j] = min(f[i][j],t);                        
            }
        }
    }

    cout<<f[1][n];
}