#include<iostream>
//扩展欧几里得
using namespace std;
typedef long long LL;

LL ret;

//求特解 a*x + b*y = gcd(a,b)
LL E(LL a,LL b,LL &x,LL &y)
{
    //出口
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    LL a1 = b;
    LL b1 = a%b;
    LL x1,y1;

    LL d = E(a1,b1,x1,y1);
    x = y1;
    y = (x1 - (a/b)*y1);

    return d;
}



int main()
{
    LL x,y;
    LL a,b;
    cin>>a>>b;
    ret = E(a,b,x,y);
}