#include<iostream>
using namespace std;

const int N = 1e5+10;
//费马小定理：if( gcd(a,p)==1 ) -> a^(p-1) = 1(mod(p))  条件：p是质数且a,p互质
//                                  "同余->模一个数相同"

//注意：使用费马小定理的时候条件一定是a,b互质！！！,且p是质数

int a,b,p,cnt;
int st[N];
int p1[N];

void get_p()
{
    for(int i=2;i<=p+10;i++)
    {
        if(!st[i])p1[++cnt] = i;
        for(int f=1;1ll * p1[f] * i <=p+10;f++)
        {
            st[i*p1[f]] = true;
            if(i%p1[f] == 0)break;
        }
    }
}

int gcd(int a,int b)
{
    if(!b)return a;
    return gcd(b,a%b);
}

int get_divide_ret()            //快速幂
{
    int k = p-2;
    int ant = 1;
    while(k)
    {
        if((k & 1) == 1)
        {
            ant = (ant * a) % p;
        }
        a = (a*a)%p;
        k = (k>>1);
    }

    return (b*ant)%p;          //b×（a的乘法逆元）
}


int main()
{
    cin>>b>>a>>p;
    if( gcd(a , p) == 1 && !st[p])cout<<"b/a % p ="<<get_divide_ret();
    else{
        //other way
    }
}