//带权并查集就是在原来的基础上 给每个节点x设置 d[x] 标记每个节点到他的父亲节点的距离
#include<iostream>
using namespace std;

//data
const int N = 1e5 + 10;
int fa[N];
int d[N];
int n;


void init()
{
    for(int i=1;i<=n;i++)
    {
        fa[i] = i;
        d[i] = 0;   //根据题目设置
    }
}

int find(int x)
{
    if(fa[x] == x)return x;     //本身是父亲节点

    int t = find(fa[x]);        //注意：先将父亲节点路径压缩，然后维护d[x]
    d[x] += d[fa[x]];

    return fa[x] = t;           //路径压缩
}

void un(int a,int b,int w)
{
    int af = find(a); int bf = find(b);
    
    if(af != bf)                //不在一个集合里面
    {
        fa[bf] = af;
        d[bf] = w + d[a] - d[b];
    }
}


int main()
{
    //---测试---
}