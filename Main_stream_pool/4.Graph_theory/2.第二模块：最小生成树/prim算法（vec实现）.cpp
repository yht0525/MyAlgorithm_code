#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e3+10;

//最小生成树 -> kk/prim

int dist[N];
struct node{
    int to;
    int val;
};

int n,m;
vector<node> vec[N];
int st[N];

int prim()
{
    int ret = 0;
    dist[1] = 0;
    
    for(int i=1;i<=n;i++)
        {
            int t = 0;
            for(int i=1;i<=n;i++)
                {
                    if(dist[t] > dist[i] && !st[i]){
                        t = i;
                    }
                }
            //t即为当前选择的最短路径
            if(dist[t] == 0x3f3f3f3f)return -1;
            st[t] = true;
            ret += dist[t];
            
            for(auto v:vec[t])
                {
                    int tar = v.to;
                    if(!st[tar] && dist[tar] > v.val){
                        dist[tar] = v.val;
                    }
                }
        }
    return ret;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        {
            int a,b,val;
            cin>>a>>b>>val;
            vec[a].push_back({b,val});
            vec[b].push_back({a,val});
        }
    //初始化
    memset(dist,0x3f,sizeof(dist));
    
    int k = prim();
    if(k == 0x3f3f3f3f){
        cout<<-1;
    }
    else{
        cout<<k;
    }
}