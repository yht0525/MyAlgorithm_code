//正难则反思想
#include<iostream>
#include<cmath>
using namespace std;
const int N = 1e6+10;

long long c[N],p[N],st[N];
long long n,cnt;

void get_p()
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i])p[++cnt] = i;
        for(int j=1;1ll * i * p[j]<=n;j++)
        {
            st[i*p[j]] = true;
            if(i%p[j]==0)break;
        }
    }
}

void get_re()
{
    int t = n;
    for(int i=1;i<=cnt;i++)
    {
        long long t1 = p[i];
        while(t/t1 > 0)         //找每一个质数在阶乘里面的数量
        {
            t/=t1;
            t1 *= p[i];
            c[i]+=t;
            t = n;
        }
    }
}

int main()
{
    cin>>n;
    get_p();
    get_re();
    for(int i=1;i<=cnt;i++)
    {
        if(c[i]!=0){
            cout<<p[i]<<" "<<c[i]<<endl;
        }
    }
}