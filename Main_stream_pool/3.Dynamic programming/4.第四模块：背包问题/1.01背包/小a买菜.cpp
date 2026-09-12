#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e4+10;
int f[N];
int w[N];
int n,m;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>w[i];

    memset(f,0,sizeof(f));
    f[0] = 1;
    for(int i=1;i<=n;i++)
    for(int j=m;j>=w[i];j--)
    {
        f[j] += f[j-w[i]];    //选
    }

    cout<<f[m];
}