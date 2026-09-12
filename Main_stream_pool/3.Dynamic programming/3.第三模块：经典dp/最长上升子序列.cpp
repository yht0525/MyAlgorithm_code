#include<iostream>
using namespace std;

const int N = 1e4;
int a[N];
int f[N];                       //注意：这里的意思是以i为末尾的子序列，如果不能以i为末尾就直接跳过！！！
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    int ret = 0;
    for(int i=1;i<=n;i++)
    {
        f[i] = 1;
        for(int j=1;j<i;j++)
        {
            if(a[j] < a[i])
            {
                f[i] = max(f[i] , f[j] + 1);        //只要比较与原来的和新的加1
            }
        }        
        ret = max(f[i],ret);
    }
    cout<<ret;
}