#include<iostream>
#include<cstring>
using namespace std;

const int N = 3e2+10;
int n;
int a[N];
int f[N][N];    //表示i到j区间可以合成的最大数

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)f[i][i] = a[i];

    for(int i=n;i>=1;i--)
    {
        for(int j=i;j<=n;j++)
        {
            for(int k=i;k<j;k++)
            {
                if(f[i][k] == 0 || f[k+1][j] == 0)continue;
                else{
                    if(f[i][k] == f[k+1][j])f[i][j] = max(f[i][j] , f[i][k] + 1);
                }
            }
        }
    }

    int ret = 0;
    for(int i=n;i>=1;i--)
    {
        for(int j=i;j<=n;j++)
        {
            if(f[i][j]!=0)ret = max(ret,f[i][j]);
        }
    }
    cout<<ret;
}