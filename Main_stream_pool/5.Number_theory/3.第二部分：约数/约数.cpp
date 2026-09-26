// ifa是b的约数，a可被b整除
// 求[1,n]的每一个数的约数 vs 求一个数的约数
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;
const int N = 1e6+10;
vector<int> d[N];
int n;

int c[N];

//两种方法求n的约数
//试除法（求每一个数的约数）
void get_pr()                                                                   //求【1，n】里面任意数的约数（记录到vector里面）
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n/i;j++)
        {
            d[i*j].push_back(i);    //正男则反：找每一个数的约数
        }
    }
}

//在分解质因数的时候累乘（求约数的数量）
// 公式：sum = (1+a1)*(1+a2)*...                                                //求一个数的约数个数，公式法
void deprime()
{
    int ret = 1;
    int t = n;
    for(int i=2;i<=n/i;i++)
    {
        int cnt = 0;
        while(t%i == 0)
        {
            t/=i;
            cnt++;
        }
        c[i] += cnt;
        if(cnt!=0)ret *= (cnt+1);
    }
    if(t>1)
    {
        c[t]++;
        ret *= 2;
    }
}

// 求约数和
// n = p1^a1 * p2^a2 * p3^a3 ...  
// sum = (1 + p1^1 + .. + p1^a1) * (1 + p2^1 +..) * ..                              //求一个数的约数之和

//优化求【1，n】约数个数                                                            //求【1，n】所有数的约数个数总和
int get()
{
    int ret = 0;
    int k = n - n/2;
    for(int i=1;i<=n/2;i++)
    {
        ret+=(n/i);
    }
    return ret+k;
}

int main()
{
    cin>>n;
}