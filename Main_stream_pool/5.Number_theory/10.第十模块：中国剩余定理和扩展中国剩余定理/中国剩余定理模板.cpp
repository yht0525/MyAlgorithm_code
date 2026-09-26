#include<iostream>
#include<cmath>
using namespace std;
typedef long long LL;
const int N = 11;

LL n[N],m[N];
LL M = 1,NUM;

//龟速乘法
LL ttx(LL a,LL b,LL mod)
{
    LL ret = 0;
    while(b)
    {
        if((b&1) == 1){
            ret = (ret+a)%mod;
        }
        a = (a + a)%mod;
        b = b>>1;
    }
    return ret;
}

//欧拉
void E(LL a,LL b,LL& x,LL& y)
{
    if(b == 0){
        x = 1;
        y = 0;
        return;
    }
    LL a1,b1,x1,y1;
    a1 = b;
    b1 = a%b;
    E(a1,b1,x1,y1);
    x = y1;
    y = (x1 - (a/b)*y1);
}

//get
LL get_result()
{
    LL ret = 0;
    for(int i=1;i<=NUM;i++)
    {
        LL k = M/m[i];
        LL x1,y1;
        E(k,m[i],x1,y1);
        x1 = (x1%m[i] + m[i])%m[i];
        ret += ttx(ttx(n[i],x1,M),k,M);
    }
    return (ret%M+M)%M;                     //ret有可能为负数！！！
}

//注意：面对可能为负数的数据，在龟速乘法的模板中 有可能为负数的数一定要放到左边

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>NUM;
    for(int i=1;i<=NUM;i++)
    {
        cin>>n[i];
    }
    for(int i=1;i<=NUM;i++)
    {
        cin>>m[i];
        M *= m[i];
    }
    cout<<get_result()%M;
}