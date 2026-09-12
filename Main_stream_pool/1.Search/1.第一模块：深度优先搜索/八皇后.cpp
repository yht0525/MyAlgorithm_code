#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 20;
int n=0;int sum=0;
int m=0;

bool col[N];
bool row[N];
bool zh[N];
bool fh[N];

struct node
{
    int x;
    int y;
    bool operator < (const node &a) const
    {
        return x > a.x;
    }
};

vector<node> v;
priority_queue<node> q;

void dfs(int cnt,int x0)
{
    if(cnt > m)
    {
        if(n < 3)
        {
        for(auto i : v)
        {
            node t;
            t.x=i.x;
            t.y=i.y;
            q.push(t);
        }
        while(q.size())
        {
            node t=q.top();
            cout<<t.y<<" ";
            q.pop();
        }
        cout<<endl;
        n++;
        return;
        }
        else
        {
            sum++;
            return;
        }
    }

        
        for(int j=1;j<=m;j++)
        {
            if(col[x0] || row[j] || fh[x0+j] || zh[j-x0+m]){continue;}
            else
            {
                //标记
                node t;
                t.x=x0;t.y=j;
                v.push_back(t);
                col[x0]=true;row[j]=true;fh[x0+j]=true;zh[j-x0+m]=true;
                
                dfs(cnt+1,x0+1);
                
                //清空现场
                col[x0]=false;row[j]=false;fh[x0+j]=false;zh[j-x0+m]=false;
                v.pop_back();
            }
        }
    
}




int main()
{
    cin>>m;
    dfs(1,1);
    cout<<sum+n;
}