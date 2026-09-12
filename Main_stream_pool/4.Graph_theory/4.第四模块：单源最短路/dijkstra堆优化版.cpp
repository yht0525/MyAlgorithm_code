#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int N = 1e5+10;

struct node{
    int num;
    int val;
    bool operator>(const node& other) const{
    return val > other.val;
    }
};

priority_queue<node,vector<node>,greater<node>> heap;
vector<node> vec[N];
int dist[N],st[N];

int n,m,s;

void dijkstra()
{
    memset(dist,0x3f3f3f3f,sizeof(dist));
    heap.push({s,0});

    while(heap.size())
    {
        node t = heap.top(); heap.pop();
        int tmp = t.num;
        
        if(st[tmp])continue;                    //st表示是否已经确定最短路
        st[tmp] = true;

        dist[tmp] = t.val;
        
        for(auto v:vec[tmp])
        {
            if(dist[tmp]+v.val < dist[v.num])
            {
                heap.push({v.num,dist[tmp]+v.val});
            }
        }
    }
}

int main()
{
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++)
    {
        int a,b,v;
        cin>>a>>b>>v;
        vec[a].push_back({b,v});
    }

    dijkstra();

    for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
}