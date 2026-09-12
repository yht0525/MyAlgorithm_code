#include<iostream>
#include<vector>
using namespace std;
int n;int m;
vector<int> v;

void dfs(int num)
{
    if(v.size() == m)
    {
        for(int i:v)
        {
            cout<<i;
        }
        cout<<endl;
        return;
    }

    for(int i=num;i<=n;i++)
    {
        v.push_back(i);
        dfs(i+1);
        //恢复现场
        v.pop_back();   
    }
}

int main()
{
    cin>>n>>m;
    dfs(1);
}