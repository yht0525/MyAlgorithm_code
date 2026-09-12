#include<iostream>
using namespace std;


int f[1005][1005];    //表示在[1,a]里面选间谍，在伪装能力不超过b的情况下，在总钱数不超过c的情况下采集到的最大资料数目
int n,m,x;
int v[105],w1[105],w2[105];



int main()
{
    cin>>n>>m>>x;

    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w1[i]>>w2[i];
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=x;j>=w2[i];j--)
        {
            for(int z=m;z>=w1[i];z--)
            {
                if(j>=w2[i] && z>=w1[i])
                {
                    f[j][z] = max(f[j][z],f[j-w2[i]][z-w1[i]]+v[i]);
                }
            }
        }
    }
    
    cout<<f[x][m];
}