#include<iostream>
#include<cstring>
using namespace std;

const int N = 5e4+10;
int f[N];      //表示在1~i种草里面采购 j磅 要用的最小钱数
int v[N],w[N];
int n,H;


int main()
{
    cin>>n>>H;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }

    memset(f,0x3f,sizeof(f));
    f[0] = 0;
    for(int i=1;i<=n;i++)
    for(int j=0;j<=H;j++)
    {
        f[j] = min(f[j],f[max(0,j-v[i])]+w[i]);
    }

    cout<<f[H];
    
}