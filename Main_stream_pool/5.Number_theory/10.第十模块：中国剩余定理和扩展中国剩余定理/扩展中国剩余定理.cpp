#include<cmath>
#include<iostream>
using namespace std;
const int N = 10+5;
typedef long long LL;
//扩展中国剩余定理，解决m[i]如果不互质就失败的问题


LL n[N],m[N];
int num;
LL k0 = 1,b0;

//扩展欧
LL E(LL a,LL b,LL& x,LL& y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL x1,y1,a1,b1;
    a1 = b;
    b1 = a%b;
    LL d = E(a1,b1,x1,y1);
    
    x = y1; y = (x1 - (a/b)*y1);
    return d;
}

void get_result()
{
    k0 = m[1];
    b0 = n[1];
    for(int i=2;i<=num;i++)
    {
        LL xt,yt;
        LL bt = abs(m[i]);
        LL c = (n[i] - b0);
        LL dt = E(k0,bt,xt,yt);

        if(c % dt != 0)return;
        xt *= c/dt;
        LL dk = bt/dt;

        // 必须先用旧 k0 更新答案
        b0 = b0 + k0 * xt;

        // 新模数 = lcm(k0, m[i])
        k0 = k0 * dk;

        // 化为最小非负解
        b0 = (b0 % k0 + k0) % k0;
    }
}

int main()
{
    cin>>num;
    for(int i=1;i<=num;i++)
    {
        // x == n[i]mod(m[i])
        cin>>n[i]>>m[i];
    }

    get_result();

    cout<<b0;
}