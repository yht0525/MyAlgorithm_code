#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N = 1e5+10;
int n,m;


//邻接矩阵存储
// int f[N][N];

// int main()
// {
//     memset(f,-1,sizeof(f));
//     int n,m;
//     cin>>n>>m;

//     for(int i=m;i<=m;i++)
//     {
//         int a,b,c;
//         cin>>a>>b>>c;

//         f[a][b] = c;
//         f[b][a] = c;
//     }
// }

//vector数组存储
// struct node{
//     int point;
//     int val;
// };

// vector<node> edges[N];

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
// }

//链式前向星存储
int ne[N*2];
int id;
int h[N];
int e[N],v[N];

void add(int a,int b,int c)
{
    id++;
    e[id] = b;
    v[id] = c;
    ne[id] = h[a];
    h[a] = id;
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
}