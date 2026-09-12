#include<iostream>
using namespace std;


//prim虚拟点算法
const int N = 510;
const int INF = 0x3f3f3f3f;

int n, A;
int dist[N], st[N], g[N][N];

int prim()
{
    for(int i=0;i<=n;i++) dist[i] = INF;
    dist[0] = 0;

    int res = 0;

    for(int i=0;i<=n;i++)
    {
        int t = -1;
        for(int j=0;j<=n;j++)
        {
            if(!st[j] && (t==-1 || dist[j] < dist[t]))      //先判断t == -1
                t = j;
        }

        st[t] = 1;
        res += dist[t];

        for(int j=0;j<=n;j++)
        {
            dist[j] = min(dist[j], g[t][j]);
        }
    }

    return res;
}

int main()
{
    cin >> A >> n;

    // 初始化
    for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
        g[i][j] = INF;

    // 读入优惠
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        int t;
        cin >> t;
        if(t != 0)
        {
            g[i][j] = t;
        }
    }

    // 虚拟点
    for(int i=1;i<=n;i++)
    {
        g[0][i] = g[i][0] = A;
    }

    cout << prim();
}