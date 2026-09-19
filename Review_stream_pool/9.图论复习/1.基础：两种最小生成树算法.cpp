#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1e5+10;
// //使用vec存储图

// struct node{
//     int point;
//     int val;
// };

// vector<node> e[N];
// int n,m;

// //两个重要的数组
// int dist[N];
// int st[N];

// int ret()
// {
//     int rnt = 0;

//     for(int i=1;i<=n;i++)
//     {
//         int t = 0;
//         for(int j=1;j<=n;j++)
//         {
//             if(!st[j] && dist[t] > dist[j]){
//                 t = j;
//             }
//         }

//         if(dist[t] == 0x3f3f3f3f)return 0x3f3f3f3f;
//         rnt+=dist[t];
//         st[t] = true;

//         for(auto i:e[t])
//         {
//             int v = i.val;
//             dist[i.point] = min(v,dist[i.point]);
//         }
//     }

//     return rnt;
// }

// int main()
// {
//     cin>>n>>m;
//     for(int i=1;i<=m;i++)
//     {
//         int a,b,val;
//         cin>>a>>b>>val;
//         e[a].push_back({b,val});
//         e[b].push_back({a,val});
//     }

//     //初始化
//     memset(dist,0x3f,sizeof(dist));
//     dist[1] = 0;

//     int get = ret();
//     if(get == 0x3f3f3f3f)cout<<"error";
//     else{
//         cout<<get;
//     }
// }


//kruskal算法
//并查集维护
///不用建图，直接识别边
// int fa[N];
// int get(int a)
// {
//     return fa[a] == a?a:get(fa[a]);
// }

// struct node{
//     int a,b,val;
// }arr[N];

// bool cmp(node &a,node &b)
// {
//     return a.val < b.val;
// }

// //参数
// int n,m;

// int main()
// {
//     cin>>n>>m;
//     for(int i=1;i<=m;i++)
//     {
//         int a,b,val;
//         cin>>a>>b>>val;
//         arr[i] = {a,b,val};
//     }

//初始化！！！
// for(int i=1;i<=n;i++)
//     {
//         fa[i] = i;
//     }


//     int cnt = 0;
//     int ren = 0;
//     sort(arr+1,arr+1+m,cmp);
//     for(int i=1;i<=m;i++)
//     {
//         int ta = arr[i].a;
//         int tb = arr[i].b;
//         int tval = arr[i].val;

//         int faa = get(ta);
//         int fab = get(tb);
//         if(faa == fab)continue;
//         else{
//             cnt++;
//             ren += tval;
//             fa[faa] = fab;
//         }
//     }


// }