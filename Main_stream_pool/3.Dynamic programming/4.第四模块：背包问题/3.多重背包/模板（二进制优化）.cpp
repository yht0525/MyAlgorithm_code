#include<iostream>
using namespace std;

const int N = 105 * 5;
int n,T;
int f[N];
int w[N],v[N],pos=0;    //pos记录数量


int main()
{
    cin>>n>>T;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        
        int t=1;
        for(int x=1;x<=6;x++)           //二进制优化 注意：二进制优化不能求方案树
        {
            if(a>=t){
                a -= t;
                w[++pos] = t*b;
                v[pos] = t*c;
                t*=2;
            }
            else{
                if(a!=0){
                    w[++pos] = a*b;
                    v[pos] = a*c;
                }
                break;
            }
        }
    }
    
    for(int i=1;i<=pos;i++)
    for(int j=T;j>=w[i];j--)
    {
        f[j] = max(f[j],f[j-w[i]]+v[i]);
    }
    
    cout<<f[T];
}