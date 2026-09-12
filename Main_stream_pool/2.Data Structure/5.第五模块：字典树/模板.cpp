//   字典树
//功能：可以快速插入和查询字符串的数据结构，利用字符串的公共前缀，按字符组成树形结构，提升了存储与查找效率
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e6+10;               //初始化
int idx;                            //idx维护节点数量
int tree[N][26] , p[N] , e[N];      //p,e数组维护节点的经过次数和结束次数

void myInsert(string &a)            //插入函数实现
{
   int cur = 0;
   p[cur]++;

   for(char ch : a)
   {
        int t = ch - 'a';
        if(tree[cur][t] == 0)tree[cur][t] = ++idx;
        cur = tree[cur][t];
        p[cur]++;
   }
   e[cur]++;
}

int find(string &a)
{
    int cur = 0;
    for(auto ch:a)
    {
        int t = ch - 'a';
        if(tree[cur][t] == 0)return 0;
        cur = tree[cur][t];
    }
    return e[cur];
}

int find_pre(string &a)
{
    int cur = 0;
    for(char ch:a)
    {
        int t = ch - 'a';
        if(tree[cur][t] == 0)return 0;
        cur = tree[cur][t];
    }
    return p[cur];
}

int main()
{
    
}