#include<iostream>
using namespace std;
const int MOD = 1e9+7;      //自定义取模符号

//打表求O（1）求组合数

typedef long long LL;
const int N = 1e5+10;

LL f[N];    //算
LL g[N];
// LL c[N];


//快速幂
LL qpow(LL a,LL b,LL mod)
{
    LL ret = 1;
    while(b)
    {
        if((b & 1) == 1)
        {
            ret = (ret * a)%mod;
        }
        a = (a*a)%mod;
        b = b>>1;
    }
    return ret;
}

//打表阶乘 打表阶乘数值和阶乘逆元
void get(int n,int mod)
{
    f[0] = 1;
    for(int i=1;i<=n;i++)
    {
        f[i] = f[i-1] * i % mod;
    }

    g[n] = qpow(f[n],mod-2,mod);
    for(int i=n-1;i>=0;i--)
    {
        g[i] = g[i+1] * (i+1) % mod;
    }
}

//查询
LL c(int n,int m,int mod)
{
    if(n>m)return 0;
    return (f[n] * g[m])%mod * g[n-m] % mod;        //注意每×一次要取模
}   

int main()
{
    int n;
    cin>>n;

}