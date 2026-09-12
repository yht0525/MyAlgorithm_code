#include<iostream>
#include<cstring>
using namespace std;

const int N = 2e2+10;
int f[N][N];        //表示从[i,j]里面找的最大得分和最小得分
int a[N];
int n;
int sum[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[n+i] = a[i];
        sum[i] = sum[i-1]+a[i];
    }
    for(int i=n+1;i<=2*n;i++)
    {
        sum[i] = sum[i-1]+a[i];
    }
    
    n*=2;
    

    //1.求最小值
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++)f[i][i] = 0;

    for(int i=n;i>=1;i--)
    {
        for(int j=i;j<=n;j++)
        {
            for(int k=i;k<j;k++)
            {
                int t = f[i][k] + f[k+1][j] + (sum[j] - sum[i-1]);
                f[i][j] = min(f[i][j] , t);
            }
        }
    }

    int len = n/2;
    int ret = 100000;
    for(int i=1;i<=n/2;i++)
    {
        int j=i+len-1;
        ret = min(ret,f[i][j]);
    }
    cout<<ret<<endl;

    //2.求最大值
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)f[i][i] = 0;

    for(int i=n;i>=1;i--)
    {
        for(int j=i;j<=n;j++)
        {
            for(int k=i;k<j;k++)
            {
                int t = f[i][k] + f[k+1][j] + (sum[j] - sum[i-1]);
                f[i][j] = max(f[i][j] , t);
            }
        }
    }

    int len1 = n/2;
    int ret1 = 0;
    for(int i=1;i<=n/2;i++)
    {
        int j=i+len1-1;
        ret1 = max(ret1,f[i][j]);
    }
    cout<<ret1;
}