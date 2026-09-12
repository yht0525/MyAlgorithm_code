#include<iostream>
using namespace std;
int n,k;
//组合型
int tar;
int path=0;

void dfs(int pos,int num)
{
    if(pos == k)
    {
        if(path == n)
        {
          tar++;      
        }
        return;
    }

    for(int i=num;i<=n;i++)
    {
        if(path + (k-pos)*i > n)return;   //在这里剪枝
        path+=i;

        dfs(pos+1,i);

        path-=i;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    dfs(0,1);
    cout<<tar;
}