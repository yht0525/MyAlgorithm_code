#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int N = 2e3+10;

struct node{
    int num;
    int val;
};

int T;
int dist[N]; vector<node> e[N*2];
int n,m;

bool bf()
{
    dist[1] = 0;

    bool jud = false;
    for(int i=1;i<=n;i++)        //松弛操作次数
    {
        jud = false;
        for(int j=1;j<=n;j++)
        {
            for(auto v:e[j])
            {
                if(dist[j]!=0x3f3f3f3f && dist[j] + v.val < dist[v.num])        //注意0x3f == 0x3f3f3f3f
                {
                    dist[v.num] = dist[j] + v.val;
                    jud = true;
                }
            }
        }
        if(jud == false)
        {
            break;
        }
    }
    
    if(jud)return true;
    else{
        return false;
    }
}

int main()
{
    cin>>T;
    while(T--)
    {
        memset(dist,0x3f,sizeof(dist));
        cin>>n>>m;

        for(int i = 1; i <= n; i++)
        {
            e[i].clear();
        }
        
        for(int i=1;i<=m;i++)
        {
            int a,b,v;
            cin>>a>>b>>v;
            e[a].push_back({b,v});
            if(v>=0)
            {
                e[b].push_back({a,v});
            }
        }
    

    if(bf())
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
        
    }
}