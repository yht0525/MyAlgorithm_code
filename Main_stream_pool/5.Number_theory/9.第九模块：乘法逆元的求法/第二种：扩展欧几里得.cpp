#include<iostream>
using namespace std;

typedef long long LL;


//条件：根据裴蜀定理：a*x + m*y = gcm(a,m) 最少要是gcm, 所以a，m一定互质
LL E(LL a,LL b,LL& x,LL& y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL x1,y1;
    LL d = E(b,a%b,x1,y1);
    x = y1;
    y = (x1 - (a/b)*y1);

    return d;
}

int main()
{
    LL a,p;
    cin>>a>>p;

    LL x1,y1;
    LL ret = 0;
    if(E(a,p,x1,y1) == 1)ret = (x1%p + p)%p;
    else{
        cout<<"error";
    }
}