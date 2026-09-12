#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e2+10;

int n,m;
int f[N][N];        //空间优化：f[k][i][j] 表示经过1~k个节点，i到j的最短距离，注意：不一定经过1~k所有点！！！

//dp代码很好写

int main()
{
    cin>>n>>m;

    //初始化
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=m;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        f[a][b] = f[b][a] = min(f[a][b],c);
    }
    for(int i=1;i<=n;i++)
    {
        f[i][i] = 0;
    }

    //开始dp 顺序 k->i->j
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        f[i][j] = min(f[i][j] , f[k][j] + f[i][k]);
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }
}