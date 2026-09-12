// #include<iostream>

//股票问题结论：任何一笔跨天的交易都可以转化成某天买隔天买的形式
#include<iostream>
#include<cstring>
using namespace std;


const int N = 1e4+10 , K = 1e2+10; 
int T,n,M;
int f[N];    //表示在1~i的货物里面选择，在j的金钱限制内的最大收益

int v[K][K],w[K][K];

int main()
{
    cin>>T>>n>>M;

    //整理数据
    for(int i=1;i<=T;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>v[i][j];
            if(i>=2)
            {
                w[i-1][j] = v[i][j] - v[i-1][j];
            }
        }  
    }
    for(int j=1;j<=n;j++)w[T][j] = v[T][j];
    

    //计算从第一天开始的本金加收益！！！ps：不用考虑最后一天
    int sum = M;
    for(int x=1;x<T;x++)
    {
        memset(f,0,sizeof(f));          //注意清空数组
        int t = sum;
        for(int i=1;i<=n;i++)
        {
            for(int j=v[x][i];j<=t;j++)
            {
                f[j] = max(f[j] , f[j-v[x][i]]+w[x][i]);    //完全背包问题
            }   
        }
        sum += max(0,f[t]);     //加上收益 ps：+max 防止亏损
    }
    
    cout<<sum;
}