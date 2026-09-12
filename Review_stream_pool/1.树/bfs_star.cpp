#include<iostream>
#include<queue>
using namespace std;

//宽度优先，用队列模拟
const int N = 1e5;
int id=0;int n;
int e[N*2];int ne[N*2];int h[N];

int st[N];

void add(int a,int b)
{
    id++;
    e[id]=b;
    ne[id]=h[a];
    h[a]=id;
}

void bfs()
{
    queue<int> qu;
    qu.push(1);
    st[1]=1;

    while(qu.size())
    {
        int t=qu.front();
        qu.pop();
        cout<<t<<endl;

        for(int i=h[t];i;i=ne[i])
        {
            int temp=e[i];
            if(!st[temp])
            {
            qu.push(temp);
            st[temp]=1;
            }
        }
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


}