

//裴蜀定理：一定存在正整数x,y,使：a*x + b*y = gcd(a,b)
//推论：    1.a*x + b*y = gcd(a,b)*n 成立
//          2.存在x1,x2,x3,...使：a1*x1 + a2*x2 + a3*x3 +... = gcd(a1,a2,a3,...) * n;

#include<iostream>
using namespace std;
const int N = 1e5+10;

int n;
int a[N];

//获得gcd
int gcd(int a,int b)
{
    if(!b)return a;
    return gcd(b,a%b);
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i] < 0)a[i] = -a[i];
    }

    int ret = a[1];
    for(int i=1;i<=n;i++)
    {
        if(i==1){
            continue;
        }
        if(a[i])ret = gcd(ret,a[i]);
    }

    cout<<ret;
}