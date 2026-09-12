#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

const int N = 1e3 + 10;
//vector
//。。。

//邻接矩阵
// int edges[N][N];
// bool st[N];
// int n, m;

// void bfs()
// {
//     queue<int> qu;
//     qu.push(1);
//     st[1] = true;

//     while(qu.size())
//     {
//         int t = qu.front();
//         qu.pop();

//         cout << t << endl;

//         for(int i = 1; i <= n; i++)
//         {
//             if(!st[i] && edges[t][i] != -1)
//             {
//                 qu.push(i);
//                 st[i] = true;
//             }
//         }
//     }
// }

// int main()
// {
//     cin >> n >> m;

//     memset(edges, -1, sizeof(edges));
//     memset(st, 0, sizeof(st));

//     for(int i = 0; i < m; i++)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;

//         edges[a][b] = 1;
//         edges[b][a] = 1;
//     }

//     bfs();
// }