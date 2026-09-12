#include<cstdio>
#include<iostream>
using namespace std;

const int N = 1e4+10;
int sum;
int n;
int f[N][1005];
int p[N],w[N],c[N];
int t;

int main()
{
    int a,b,c1,d;
    scanf("%d:%d %d:%d %d",&a,&b,&c1,&d,&n);
    t = a*60+b - (c1*60+d);
    t = -t;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>c[i]>>p[i];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=t;j++)
        {
            f[i][j] = f[i-1][j];
            if(p[i] == 1){                                                      //只用混合之前的三种背包即可
                if(j>=w[i])f[i][j] = max(f[i][j],f[i-1][j-w[i]]+c[i]);
            }
            else if(p[i] == 0){
                if(j>=w[i])f[i][j] = max(f[i][j],f[i][j-w[i]]+c[i]);
            }
            else{
                for(int x=1;x<=p[i];x++){
                    if(j>=x*w[i]){
                        f[i][j] = max(f[i][j],f[i-1][j-x*w[i]]+x*c[i]);
                    }
                }
            }
        }
    }

    cout<<f[n][t];
}