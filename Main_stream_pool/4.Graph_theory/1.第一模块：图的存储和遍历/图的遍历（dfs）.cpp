#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
const int N = 1e3;

//1.dfs遍历

//邻接矩阵
// int edges[N][N];
// int st[N];
// int n,m;

// void dfs(int a)
// {
//     cout<<a<<endl;
//     st[a] = true;

//     for(int i=1;i<=n;i++)
//     {
//         if(!st[i] && edges[a][i]!=-1){
//             dfs(i);
//         }
//     }
// }

// int main()
// {
//     memset(edges,-1,sizeof(edges));

//     cin>>n>>m;
//     for(int i=1;i<=m;i++)
//     {
//         int a,b,c;
//         cin>>a>>b>>c;
//         edges[a][b] = c;
//         edges[b][a] = c;
//     }

//     dfs(1);
// }

//vec数组
// struct node{
//     int p;
//     int val;
// };

// vector<node> edges[N];
// int st[N];
// int n,m;


// void dfs(int a)
// {
//     cout<<a<<endl;
//     st[a] = true;

//     for(auto i:edges[a])
//     {
//         if(!st[i.p]){
//             dfs(i.p);
//         }
//     }
// }


// int main()
// {
//     cin>>n>>m;

//     for(int i=1;i<=m;i++)
//     {
//         int a,b,c;
//         cin>>a>>b>>c;

//         edges[a].push_back({b,c});
//         edges[b].push_back({a,c});
//     }

//     dfs(1);
// }

//链式前向星
int ne[N*2],e[N],w[N],h[N*2];
int id;
int st[N];

int n,m;

void add(int a,int b,int c)
{
    id++;
    e[id] = b;
    w[id] = c;
    ne[id] = h[a];
    h[a] = id;
}

void dfs(int a)
{
    cout<<a<<endl;
    st[a] = true;
    
    for(int i=h[a];i!=0;i=ne[i])
    {
        int t = e[i];
        if(!st[t]){
            dfs(t);
        }
    }
}



int main()
{
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        add(a,b,c);
        add(b,a,c);
    }

    dfs(1);
}