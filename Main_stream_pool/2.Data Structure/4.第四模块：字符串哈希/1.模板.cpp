//前缀哈希数组
#include<iostream>
using namespace std;

//用unsign long long存 -> 可自动取模
typedef unsigned long long ULL;
const int N = 1e6 + 10,P = 13331;
char s[N];                       //要存的字符串
int len;
ULL f[N];   //前缀和
ULL p[N];   //记录p的n次方

void init_hash()
{
    f[0] = 0; p[0] = 1;
    for(int i=1;i<=len;i++)
    {
        f[i] = f[i-1] * P + s[i];
        p[i] = p[i-1] * P;
    }
}

ULL get(int l,int r)
{
    return f[r] - f[l-1] * p[r-l+1];
}

int main()
{
    
}