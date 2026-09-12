#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;
const int N = 1e4+10;

struct node{
    int num;
    int val;
};

vector<node> e[N];

int n,m,s;
int dist[N],st[N];
queue<int> qu;

void spfa()
{
    memset(dist,0x3f,sizeof(dist));
    dist[s] = 0;
    
    qu.push(s);
    st[s] = true;

    while(qu.size())
    {
        int t = qu.front();
        qu.pop();
        st[t] = false;

        for(auto j:e[t])
        {
            if(dist[j.num] > dist[t]+j.val)         //只用更新松弛的边
            {
                dist[j.num] = dist[t]+j.val;        //先更新，如果不在队列就加上
                if(!st[j.num])
                {
                    qu.push(j.num);
                    st[j.num] = true;
                }
            }
        }
    }

    for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
}

int main()
{
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++)
    {
        int a,b,v;
        cin>>a>>b>>v;
        e[a].push_back({b,v});
    }

    spfa();
}