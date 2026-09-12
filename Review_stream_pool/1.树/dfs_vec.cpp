#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5;
vector<int> e[N];
int n;
int st[N];

void dfs(int a)
{
    cout<<a<<endl;
    st[a]=1;

    for(auto i:e[a])
    {
        if(!st[i])dfs(i);
    }
}


int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    dfs(1);
}