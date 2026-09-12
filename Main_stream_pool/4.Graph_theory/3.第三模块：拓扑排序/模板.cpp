#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int N = 1e2+10;

vector<int> res;

int n;
struct node{
    int ne;
    int num;
    vector<int> v;
}arr[N];

queue<node> qu;
int stk[N];

void bfs()
{
    while(qu.size())
    {
        node t = qu.front();
        qu.pop();
        stk[t.num] = true;
        res.push_back(t.num);
        
        for(auto i:t.v)
        {
            arr[i].ne--;
        }
        for(int i=1;i<=n;i++)
        {
            if(!stk[i] && arr[i].ne == 0)
            {
                qu.push(arr[i]);
                stk[i] = true;
            }
        }
    }
}

int main()
{
    cin>>n;
   
    for(int i=1;i<=n;i++)
    {
        arr[i].num = i;
        int t;
        while(cin>>t,t!=0)
        {
            arr[t].ne++;
            arr[i].v.push_back(t);
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(arr[i].ne == 0)
        {
            qu.push(arr[i]);
            stk[i] = true;
        }
    }
    
    bfs();

    for(int i:res)
    {
        cout<<i<<" ";
    }
}