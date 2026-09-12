#include<iostream>
#include<cstring>
using namespace std;

const int N = 5010;
const int INF = 0x3f3f3f3f;

//距离和加入状态表示
int dist[N],st[N];

int edges[N][N];
int n,m;

int prim()
{
    dist[1] = 0;
    int ret = 0;

    for(int i=1;i<=n;i++)
    {
        //找最近的点
        int t = 0;
        for(int j=1;j<=n;j++)
        {
            if(!st[j] && dist[j] < dist[t])
            {
                t = j;
            }
        }

        //判断是否联通
        if(dist[t] == INF)return INF;
        st[t] = true;
        ret += dist[t];

        //更新
        for(int j=1;j<=n;j++)
        {
            dist[j] = min(dist[j] , edges[t][j]);
        }
    }

    return ret;
}

int main()
{
    memset(dist,INF,sizeof(dist));
    memset(edges,INF,sizeof(edges));

    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        //防止重边
        edges[a][b] = edges[b][a] = min(edges[a][b] , c);
    }

    int ret1 = prim();
    
    if(ret1 == INF){
        cout<<"orz"<<endl;
    }
    else{
        cout<<ret1;
    }
}