#include<iostream>
using namespace std;
typedef long long LL;

const int P = 1e9+7;

//适用于m很小的情况 , 即使时单次查询但是m值很小，也可以使用
//快速幂
LL mi(LL a,LL b,LL mod)
{
    LL ret = 1;
    while(b)
    {
        if((b & 1) == 1){
            ret = (ret * a)%mod;
        }
        a = (a * a)%mod;
        b = (b>>1);
    }
    return ret;
}

LL c(LL n,LL m,LL p)
{
    if(n < m){
        return 0;
    }
    LL up = 1;
    LL down = 1;
    for(int i=n;i>=n-m+1;i--)       //循环m次：因此如果m过大就会超时
    {
        up = up * (i%p) % p;
    }
    for(int i=2;i<=m;i++)
    {
        down = down * (i%p) % p;
    }

    LL ret = up * mi(down,p-2,p);
    return ret;
}

int main()
{


    
}