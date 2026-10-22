#include<iostream>
using namespace std;
typedef long long LL;

const LL MOD = 1e9+7;
const int N = 1e6+10;
LL d[N];

LL tm(LL a,LL b,LL mod)
{
    LL ret = 0;
    while(b)
    {
        if(b&1){
            ret = (ret + a)%mod;
        }
        a = (a+a)%mod;
        b = b>>1;
    }
    return ret;
}

void get_table()
{
    int n = 1e6;
    d[0] = 1;
    d[1] = 0;
    d[2] = 1;
    for(int i=3;i<=n;i++)
    {
        d[i] = tm((d[i-1] + d[i-2])%MOD,i-1,MOD);
    }
}

LL qpow(LL a,LL b,LL mod)
{
    LL ret = 1;
    while(b)
    {
        if(b & 1){
            ret = (ret * a)%MOD;
        }
        a = (a * a)%MOD;
        b = b>>1;
    }
    return ret;
}

LL fac[N], ifac[N];

void init()
{
    fac[0] = 1;

    for(int i=1;i<N;i++)
    {
        fac[i] = fac[i-1] * i % MOD;
    }

    ifac[N-1] = qpow(fac[N-1],MOD-2,MOD);

    for(int i=N-2;i>=0;i--)
    {
        ifac[i] = ifac[i+1] * (i+1) % MOD;
    }
}

LL c(int n,int m)
{
    if(m>n || m<0)return 0;

    return fac[n] * ifac[m] % MOD * ifac[n-m] % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;    
    get_table();
    init();
    while(t--)
    {
        LL nk,mk;
        cin>>nk>>mk;
        LL m = c(nk,mk);
        LL n = d[nk-mk];
        LL ret = tm(m,n,MOD);
        cout<<ret<<endl;
    }
}