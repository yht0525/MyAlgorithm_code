#include<iostream>
using namespace std;

const int N = 1e5;
int n;
int a[N];
int b[N];
int f1[N];
int f2[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[n-i+1] = a[i];
    }

    for(int i=1;i<=n;i++)
    {
        f1[i] = 1;
        f2[i] = 1;
        for(int j=1;j<i;j++)
        {
            if(a[j] < a[i])f1[i] = max(f1[i],f1[j]+1);
            if(b[j] < b[i])f2[i] = max(f2[i],f2[j]+1);
        }
    }

    int ret = 0;
    for(int i=1;i<=n;i++)
    {
        ret = max(ret,f1[i]+f2[n-i+1]-1);
    }
    
    cout<<n-ret;
}