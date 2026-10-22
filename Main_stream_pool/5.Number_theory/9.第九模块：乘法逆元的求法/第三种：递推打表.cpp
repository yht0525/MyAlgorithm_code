#include<iostream>
using namespace std;

typedef long long LL;
const int N = 1e5+10;

LL inv[N];

//打表：条件是：[1,n]中所有数和p互质，一个数在mod x下有逆元的条件是->gcd(n,x) = 1

void get(int n,int mod)
{
    inv[1] = 1;
    for(int i=2;i<=n;i++)
    {
        inv[i] = mod - (mod/i)*inv[mod%i]%mod;
    }
} 

int main()
{
    



}