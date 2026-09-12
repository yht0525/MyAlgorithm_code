#include<iostream>
using namespace std;
const int N = 1e5;
int n;int id=0;
//深度优先，用递归模拟
int h[N];int e[N*2];int ne[N*2];int st[N*2];

void add(int a,int b)
{
    id++;
    e[id]=b;
    ne[id]=h[a];
    h[a]=id;
}

void dfs(int a)
{
    cout<<a<<endl;
    st[a]=1;

    for(int i=h[a];i;i=ne[i])
    {
        int v=e[i];
        if(!st[v])dfs(v);
    }
}

int main()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }

    dfs(1);
}