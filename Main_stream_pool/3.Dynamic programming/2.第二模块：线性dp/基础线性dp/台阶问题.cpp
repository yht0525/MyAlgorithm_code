#include<iostream>
using namespace std;
const int N = 1e5+10;
const int P = 100003;
int n,k;
long long f[N];

int main()
{
    cin>>n>>k;
    f[0] = 1;
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=i-1;j++)
        {
            f[i] += (f[j])%P; 
        }
    }

    for(int i=k+1;i<=n;i++)
    {
        for(int j = i-k; j< i ;j++)
        {
            f[i] += (f[j])%P;
        }
    }

    cout<<f[n]%P;
}