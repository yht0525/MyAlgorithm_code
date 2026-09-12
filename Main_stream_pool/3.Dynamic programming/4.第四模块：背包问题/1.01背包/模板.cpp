#include<cstring>
#include<iostream>
using namespace std;

const int N=1e3+10;
int f[N];        //代表在【1，i】以内 用j的体积 可以选到的最大值

int w[N];
int v[N];
int n,mw;

// int main()
// {
//     cin>>n>>mw;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>v[i]>>w[i];
//     }
    
//     f[0][0] = 0;
//     for(int i=1;i<=mw;i++)f[0][i] = 0;
    
//     for(int i=1;i<=n;i++)
//     for(int j=1;j<=mw;j++)
//     {
//         f[i][j] = f[i-1][j];
//         if(j-v[i] >= 0)f[i][j] = max(f[i-1][j],f[i-1][j-v[i]]+w[i]);    
//     }
    
//     cout<<f[n][mw]<<endl;
    
//     memset(f,0,sizeof(f));              //第二问：初始化改变！！！
//     f[0][0] = 0;
//     for(int i=1;i<=mw;i++)f[0][i] = -1e9;
    
//     for(int i=1;i<=n;i++)
//     for(int j=1;j<=mw;j++)
//     {
//         f[i][j] = f[i-1][j];
//         if(j-v[i] >= 0)f[i][j] = max(f[i-1][j],f[i-1][j-v[i]]+w[i]);    
//     }
    
//     if(f[n][mw]>0)cout<<f[n][mw];
//     else{
//         cout<<0;
//     }
// }

//空间优化          直接删掉一维，并且改变遍历顺序
int main()
{
    cin>>n>>mw;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }
    
    f[0] = 0;
    for(int i=1;i<=mw;i++)f[i] = 0;
    
    for(int i=1;i<=n;i++)
    for(int j=mw;j>=v[i];j--)
    {
        // f[i][j] = f[i-1][j];
        if(j-v[i] >= 0)f[j] = max(f[j],f[j-v[i]]+w[i]);    
    }
    
    cout<<f[mw]<<endl;
    
    memset(f,0,sizeof(f));              //第二问：初始化改变！！！
    f[0] = 0;
    for(int i=1;i<=mw;i++)f[i] = -1e9;
    
    for(int i=1;i<=n;i++)
    for(int j=mw;j>=v[i];j--)           //时间优化：根据if条件优化！！！
    {
        if(j-v[i] >= 0)f[j] = max(f[j],f[j-v[i]]+w[i]);    
    }
    
    if(f[mw]>0)cout<<f[mw];
    else{
        cout<<0;
    }
}
