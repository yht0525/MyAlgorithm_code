#include<iostream>
#include<set>
#include<cmath>
using namespace std;
typedef long long LL;
const int N = 1e5+10;

LL hp[N];
LL ihp[N];
LL give[N];
int m,n;

LL get_mi(LL a,LL b,LL mod)
{
    a = (a % mod + mod) % mod;
    b = (b % mod + mod) % mod;
    LL ret = 0;
    while(b)
    {
        if((b & 1) == 1){
            ret = (ret + a)%mod;
        }
        a = (a + a)%mod;
        b = b>>1;
    }
    return ret;
}

LL E(LL a,LL b,LL& x,LL& y)
{
    if(b == 0){
        x=1;
        y=0;
        return a;
    }

    LL a1,b1,x1,y1;
    a1 = b;
    b1 = a%b;
    LL d = E(a1,b1,x1,y1);
    x = y1; y = x1 - (a/b)*y1; 
    return d;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        bool jud = true;
        multiset<LL> wep;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>hp[i];   
        }
        for(int i=1;i<=n;i++){
            cin>>ihp[i];
        }
        for(int i=1;i<=n;i++){
            cin>>give[i];
        }
        for(int i=1;i<=m;i++){
            LL t;cin>>t;
            wep.insert(t);
        }

        LL k0 = 1;
        LL b0 = 0;

        LL limit = 0;
        for(int i=1;i<=n;i++)
        {
            //取出武器
            auto it = wep.upper_bound(hp[i]);
            if(it != wep.begin())--it;
            LL dt = *it;
            wep.erase(it);

            //求杀死dro的最小次数
            limit = max(limit, (hp[i] + dt - 1) / dt);
            
            LL at = k0 * dt;
            LL ct = hp[i] - dt * b0;
            LL bt = ihp[i];
            LL x1,y1;
            LL d = E(at,bt,x1,y1);

            if(ct % d != 0){
                cout<<-1<<endl;
                jud = false;
                break;
            }
            LL dk = bt/d;

            //============在这一步要用龟速乘避免负数和溢出=============
            x1 = get_mi(ct/d,x1,dk);
            
            // x1 = (x1%dk + dk)%dk;
            b0 = k0 * x1 + b0;
            k0 = k0 * dk;

            wep.insert(give[i]);
        }

        if(jud){
            if(b0 < limit)b0 += (limit - b0 + k0 - 1) / k0 * k0;
            cout<<b0<<endl;
        }
    }
}