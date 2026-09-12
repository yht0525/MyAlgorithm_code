#include<queue>
#include<vector>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 2e3+10;
int T;
int n,m;

struct node{
    int num;
    int val;
};

vector<node> e[N];

int dist[N],st[N];
int cnt[N];

bool spfa()
{
    queue<int> qu;
    qu.push(1);
    
    cnt[1] = 0;
    st[1] = true;
    dist[1] = 0;
    
    while(qu.size())
    {
        int t = qu.front();
        qu.pop();
        st[t] = false;

        for(auto i:e[t])
        {
            if(dist[t]!=0x3f3f3f3f && dist[t]+i.val < dist[i.num])
            {
                dist[i.num] = dist[t]+i.val;
                cnt[i.num] = cnt[t] + 1;
                if(cnt[t] >= n)return true;
                if(!st[i.num])
                {
                    qu.push(i.num);     
                    st[i.num] = true;
                }
            }
        }
    }

    return false;
}


int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        memset(dist,0x3f,sizeof(dist));
        memset(cnt,0,sizeof(cnt));
        memset(st,0,sizeof(st));
        
        for(int i=1;i<=n;i++)
        {
            e[i].clear();    
        }
        
        for(int i=1;i<=m;i++)
        {
            int a,b,v;
            cin>>a>>b>>v;
            if(v>=0)
            {
                e[a].push_back({b,v});
                e[b].push_back({a,v});
            }
            else
            {
                e[a].push_back({b,v});
            }
        }

        if(spfa())
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}