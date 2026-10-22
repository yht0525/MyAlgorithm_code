#include<iostream>
using namespace std;

typedef long long LL;
const int K = 200;
const int N = 1000;

LL n;
int d[200][K];
LL k,x;

LL qpow(LL a,LL b,LL mod)
{
    a = a%mod;
    LL ret = 1;
    while(b)
    {
        if(b&1){
            ret = ret * a % mod;
        }
        a = (a*a)%mod;
        b= b>>1;
    }
    return ret;
}

void add(int a[],int b[],int c[])
{
    int inpu = 0;
    for(int i=0;i<K;i++)                //高精度算法
    {
        int pre = b[i] + c[i] + inpu;
        inpu = pre/10;
        a[i] = pre%10;
    }
}

void get_table()
{
    d[0][0] = 1;
    //计算杨辉三角形 -> c(n,m) n -> (1,1000) m -> (1,100);
    for(int i=1;i<=n-1;i++)
    {   
        for(int j=100;j>=1;j--)    //输出c(n,m)
        {
            add(d[j],d[j],d[j-1]);
        }
    }
}

int main()
{
    cin>>k>>x;
    n = qpow(x,x,1000);

    get_table();
    bool jud = true;
    for(int i=K-1;i>=0;i--)            //输出数组
    {
        if(d[k-1][i] == 0 && jud){
            continue;
        }
        else{
            jud = false;
            cout<<d[k-1][i];
        }
    }
    if(jud){
    cout<<0<<" ";
    }
}