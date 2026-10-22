#include<iostream>
using namespace std;
typedef long long LL; 
const int N = 1e3+10;

//！！！！！！！！ ===========================适用于取模数字非质数而不能使用费马小定理的情况=================================

const int mod = 1e9+7;
LL f[N][N];

//打表（动态规划求杨辉三角）
void dp(LL p)   //求到c(p,x)
{

    for(int i=0;i<=p;i++)
    {
        f[i][0] = 1;
        for(int j=1;j<=i;j++)                               //注意：存在c(n,0) = 1!!!   j从1开始循环
        {
            f[i][j] = (f[i-1][j-1] + f[i-1][j]) % mod;
            
            //高精度：
            //  for(int xi=0;xi<=150;xi++)f[i][j][xi] = f[i-1][j][xi] + f[i-1][j-1][xi] -> 缺进位
        
        }
    }

}

LL c(int n,int m)
{
    if(n < m)return 0;
    return f[n][m];
}

int main()
{

    dp(5);

    cout<<c(4,3);
}