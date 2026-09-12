#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e3+10;
int n,V;
int v[N],w[N];
int f[N][N];

int main()
{
    cin>>n>>V;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=V;j++)
        {
            f[i][j] = f[i-1][j];
            if(j >= v[i])
            {
                f[i][j] = max(f[i-1][j],f[i][j-v[i]]+w[i]);     //和01不一样的地方：优化！！！
            }
        }
    }
    
    cout<<f[n][V]<<endl;
    
    memset(f,0,sizeof(f));
    for(int i=1;i<=V;i++)f[0][i] = -1e9;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=V;j++)
        {
            f[i][j] = f[i-1][j];
            if(j >= v[i])
            {
                f[i][j] = max(f[i-1][j],f[i][j-v[i]]+w[i]);
            }
        }
    }
    
    if(f[n][V]>0)cout<<f[n][V];
    else{
        cout<<0;
    }
}