#include<iostream>
using namespace std;

const int N = 1e5;
int fa[N];          //双亲表示法：建立数列表示每个元素的父亲节点

//先补充并查集的概念：
// 需要维护若干集合，基于集合开展下列操作
// 1.查询：查询x属于那个集合
// 2.合并：将两个集合合并
// 3.判断：判断元素是否在同意集合内
// 4.引出：union find

//=============实现：==============
void init(int a)
{
    for(int i=1;i<=a;i++)fa[i] = i;
}

int find(int x)
{
    // return fa[x] == x ? x : find(fa[x]);
    //优化：路径压缩
    return fa[x] == x ? x : fa[x] = find(fa[x]);    //=======注意！！！递归要用 f[x]!!!=======
}

void un(int a,int b)
{
    int af = find(a);
    int bf = find(b);

    fa[bf] = af;
}

bool jud(int a,int b)
{
    return fa[a] == fa[b];
}

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int s,f;
        cin>>f>>s;
        fa[s] = f;
    }

    cout<<find(2)<<endl;
    cout<<find(8)<<endl;
}