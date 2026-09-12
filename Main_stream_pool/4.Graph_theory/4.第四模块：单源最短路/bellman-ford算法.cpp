#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N = 1e4+10;

struct node{
    int num;
    int val;
};

vector<node> e[N];
int n,m,s;
int dist[N];

void bf()
{
    memset(dist,0x3f3f3f3f,sizeof(dist));
    dist[s] = 0;

    int cnt = 1;
    while(cnt){
        cnt = 0;
        for(int i=1;i<=n;i++)
        {
            for(auto j:e[i])
            {
                if(dist[i]+j.val < dist[j.num])
                {
                    cnt++;
                    dist[j.num] = dist[i]+j.val;
                }
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
        e[a].push_back({b,v});
    }

    bf();

    for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
}