#include<iostream>
using namespace std;
typedef long long LL;

//费马小定理：a^(p-2) = a^(-1)
//在a,p互质 且 p为质数时成立

LL qpow(LL a,LL b,LL mod)
{
    LL ret = 1;
    while(b)
    {
        if((b & 1) == 1){
            ret = (ret * a)%mod;
        }
        a = (a*a)%mod;
        b = b>>1;
    }
    return ret;
}

int main()
{
    LL a,b;
    cin>>a>>b;
    
    cout<<"a^-1 in mod b = "<<qpow(a,b-2,b);
}