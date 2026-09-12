#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int N = 1e5;
vector<int> e[N];
int n;

int st[N];

void bfs()
{
    queue<int> qu;
    qu.push(1);
    st[1]=1;

    while(qu.size()>0)
    {
        int t=qu.front();
        cout<<t<<endl;

        qu.pop();
        for(auto i:e[t])
        {
            if(!st[i])qu.push(i);
            st[i]=1;
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
        e[a].push_back(b);
        e[b].push_back(a);
    }

    bfs();
}