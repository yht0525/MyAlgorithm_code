#include<iostream>
#include<map>
using namespace std;
const int MOD = 1e9+7;
const int N = 1e6+10;
typedef long long LL;

int n,m,k;
// map<int,int> mp;             注意不要用map

//求c
LL qpow(LL a,LL b)
{
    LL ret = 1;
    while(b)
    {
        if(b&1){
            ret = (ret * a)%MOD;
        }
        a = (a * a)%MOD;
        b = b>>1;
    }
    return ret;
}
LL f[N];
LL M[N];
void get_table()
{
    f[0] = 1;
    for(int i=1;i<=n;i++)
    {
        f[i] = f[i-1] * i %MOD;
    }

    M[n] = qpow(f[n],MOD-2);
    for(int i=n-1;i>=0;i--){
        M[i] = M[i+1] * (i+1) %MOD;
    }
}

LL get(LL n1,LL m1)
{
    if(n1 < m1)return 0;
    return f[n1] * M[n1-m1]%MOD * M[m1]%MOD;
}

LL C[N];
int cnt[N];
LL F[N];         //dp      

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        LL t;
        cin>>t;
        cnt[t]++;
    }

    get_table();
    
    //建立c数组
    for(int i=1;i<=m;i++)
    {
        int x = 0;
        for(int j=1;j<=(m/i);j++)
        {
            if(cnt[i*j]){
                x+=cnt[i*j]; 
                // cout<<x<<endl;;
            }
        }
        C[i] = get(x,k);
        // cout<<C[i]<<endl;
    }
    
    for(int i=m;i>=1;i--)
    {
        F[i] = C[i];
        for(int j=2;j<=(m/i);j++)
        {
            F[i] = ((F[i] - F[i*j])%MOD+MOD)%MOD;
        }
    }

    for(int i=1;i<=m;i++)
    {
        cout<<F[i]<<" ";
    }
}