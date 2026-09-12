#include<vector>
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5;
int m,n;
int st[N];
vector<int> v;

void dfs()
{
    if(v.size() == m)
    {
        for(auto i:v)cout<<i<<" ";
        cout<<endl;
        return;
    }

    for(int i=1;i<=n;i++)
    {
        if(st[i]!=1)
        {
            v.push_back(i);
            st[i]=1;
        }
        else
        {
            continue;
        }
        dfs();

        //恢复现场
        v.pop_back();
        st[i]=0;
    }
}

int main()
{
    cin>>n>>m;
    dfs();
}

//易错点补充：33行的st[i]是最后一层递归的i，所以删除之后要默认他为没用过的数字