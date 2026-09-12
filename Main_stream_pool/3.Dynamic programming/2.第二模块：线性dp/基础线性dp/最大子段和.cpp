#include<iostream>
using namespace std;

const int N = 2e5+10;
int f[N];
int n;

int main()
{
    cin>>n;    
    f[0] = 0;
    int ret = -1e4;
    for(int i=1;i<=n;i++)
    {
        cin>>f[i];
        f[i] = max(f[i-1]+f[i] , f[i]);
        ret = max(ret , f[i]);
    }
    cout<<ret;
}