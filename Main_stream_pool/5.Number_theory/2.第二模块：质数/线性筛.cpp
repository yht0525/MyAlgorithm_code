//欧拉筛
#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e5+10;

bool st[N];
int p[N];
int cnt,n;

int main()
{
    cin>>n;

    for(int i=2;i<=n;i++)
    {
        if(st[i])p[++cnt] = i;

        for(int j=1;1ll * i * p[cnt] <n;j++)
        {
            st[i * p[j]] = true;
            if(i % p[j] == 0)break;
        }
    }

    cout<<cnt;
}