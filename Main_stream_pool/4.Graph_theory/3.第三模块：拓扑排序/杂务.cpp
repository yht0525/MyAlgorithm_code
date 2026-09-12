#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
const int N = 1e4+10;

//dp动态规划

struct node{
    int ne;
    int nt;
    vector<int> v;
    vector<int> last;
}arr[N];

int n;
int f[N];
int le[N];
queue<int> qu;


int main()
{
    memset(f,0x3f3f3f3f,sizeof(f));

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;cin>>a>>le[a];
        int t;
        while(cin>>t,t!=0)
        {
            arr[a].ne++;
            arr[a].nt++;
            arr[t].v.push_back(a);
            arr[a].last.push_back(t);
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(arr[i].ne == 0)
        {
            qu.push(i);
        }
    }

    int pos = 0;
    int res[n];
    while(qu.size())
    {
        int t = qu.front();
        res[++pos] = t;
        qu.pop();
        for(auto i:arr[t].v)
        {
            arr[i].ne--;
            if(arr[i].ne == 0)
            {
                qu.push(i);
            }
        }
    }

    int ret = 0;
    for(int j=1;j<=n;j++)
    {
        int i = res[j];
        if(arr[i].nt == 0)
        {
            f[i] = le[i];
        }
        else{
            int t=0;
            for(auto j:arr[i].last)
            {
              t = max(f[j],t);
            }
            f[i] = t+le[i];
        }

        ret = max(f[i],ret);
    }

    cout<<ret;
}