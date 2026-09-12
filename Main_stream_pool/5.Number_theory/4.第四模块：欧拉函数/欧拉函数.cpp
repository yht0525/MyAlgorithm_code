#include<iostream>
#include<cmath>
using namespace std;
const int N = 1e5+10;
//互质：a与b的gcd=1
//欧拉函数：f(x) = 【1，x】中和x互质的数的个数
//积性函数：f(x*y) = f(x) * f(y)

//求每个数的欧拉函数
int n;
int get_num()
{
    int ret = n;
    int t = n;
    for(int i=2;i<=n;i++)
    {
        if(t%i == 0){
            ret = (ret/i)*(i-1);
            while(t%i==0)
            {
                t/=i;
            }
        }
    }
    if(t > 1)
    {
        ret = ret/(t) * (t-1);
    }

    return ret;
}

//积性函数+欧拉筛 打表
int st[N];
int phi[N];
int p[N];
int cnt;

void print_table()
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i])p[++cnt] = i;
        for(int j=1;1ll * i * p[j]<=n;j++)
        {
            int x = i*p[j];
            st[x] = true;
            
            if(i%p[j] == 0){
                phi[x] = p[j] * phi[i];
                break;
            }
            else{
                phi[x] = (p[j]-1) * phi[i];
            }
        }
    }
}


int main()
{
    cin>>n;

    cout<<get_num();
}