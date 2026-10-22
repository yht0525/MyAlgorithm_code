#include<iostream>
using namespace std;

typedef long long LL;
const int N = 1e4+10;
//卢卡斯定理：C(n,m) 和 C(n/mod,m/mod) * C(n%mod,m%mod) % (mod) 是同余的，在(mod p)的条件下
//所以用递归 由lucas(LL n,LL m,LL p) = lucas( n/p, m/p, p) * C(n%p,m%p,p) % p 将所有要求的数据压缩到p的范维内

//先用方式3打表全部C
LL n,m,p;

LL qpow(LL a,LL b,LL p)
{
    LL ret = 1;
    while(b)
    {
        if((b & 1) == 1){
            ret = (ret * a)%p;
        }
        a = (a * a)%p;
        b = b>>1;
    }
    return ret;
}

LL f[N],g[N];

void makeTable()
{
    int n = p-1;
    f[0] = 1;
    for(int i=1;i<=n;i++)
    {
        f[i] = f[i-1]*i % p;
    }

    g[n] = qpow(f[n],p-2,p);
    for(int i=n-1;i>=0;i--)
    {
        g[i] = g[i+1] * (i+1) % p;
    }
}

LL C(LL a,LL b,LL mod)
{
    if(a<b)return 0;
    else{
        return ((f[a] * g[a-b])%mod * g[b])%mod;
    }
}

//递归卢卡斯
LL lucas(LL n1,LL m1,LL mod)
{
    if(m1 == 0)return 1;
    else{
        return lucas(n1/mod,m1/mod,mod) * C(n1%mod,m1%mod,mod) % mod;
    }
}

int main()
{

}