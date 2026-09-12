#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
const int N = 5e5;

struct node{
    int num;
    int val;
};

vector<node> out[N];
int dist[N],st[N];

int n,m,s;

void djj()
{
    for(int i=1;i<n;i++)
    {
        int t = 0;
        for(int j=1;j<=n;j++)
        {
            if(!st[j] && dist[t] > dist[j])         //核心贪心手法
            {
                t = j;
            }
        }

        for(auto tmp:out[t])
        {
            dist[tmp.num] = min(dist[tmp.num] , dist[t]+tmp.val);    
        }
        
        st[t] = true;
    }
}

int main()
{
    int inf = (int)pow(2,31) - 1;
    
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++)
    {
        int a,b,v;
        cin>>a>>b>>v;

        out[a].push_back({b,v});
    }
    
    memset(dist,0x3f3f3f3f,sizeof(dist));
    dist[s] = 0;
    
    djj();

    for(int i=1;i<=n;i++)
    {
        if(dist[i] != 0x3f3f3f3f)cout<<dist[i]<<" ";
        else{
            cout<<inf<<" ";
        }
    }
}