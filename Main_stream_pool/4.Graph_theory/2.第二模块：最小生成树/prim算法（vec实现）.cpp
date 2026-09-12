#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int N = 5050;
const int INF = 0x3f3f3f3f;

struct node{
    int p;
    int val;
};

vector<node> v[N];
int n,m;

int dist[N],st[N];

int prim()
{
    dist[1] = 0;
    int ret = 0;

    for(int i=1;i<=n;i++)
    {
        int t = 0;
        for(int j=1;j<=n;j++)
        {
            if(!st[j] && dist[j] < dist[t])         //找最近点
            {
                t = j;
            }
        }

        if(dist[t] == INF)return INF;
        st[t] = true;
        ret += dist[t];

        for(auto j : v[t])                          //目标点到树的最短距离
        {
            int t1 = j.p;
            int t2 = j.val;
            
            dist[t1] = min(dist[t1] , t2);
        }
    }
    return ret;
}

int main()
{
    memset(dist,INF,sizeof(dist));

    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
         v[a].push_back({b,c});
         v[b].push_back({a,c});
    }

    int ret = prim(); 
    if(ret == INF){
        cout<<"orz"<<endl;
    }
    else{
        cout<<ret<<endl;
    }
}