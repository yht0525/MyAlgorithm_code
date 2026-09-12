#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 1e5+10;
int h[N];
int n,m;

struct node{
    int a,b,val;
}arr[N*10*2];

struct node2{
    int a;
    int val;
};

bool cmp(node& a1,node& b1)
{
    if(h[a1.b]!=h[b1.b])
    {
        return h[a1.b] > h[b1.b];
    }
    else{return a1.val < b1.val;}
}

int pos;
int cnt;
int st[N];
vector<node2> vec[N*10];

void dfs(int a1)
{
    pos++;
    st[a1] = true;
    
    for(auto i:vec[a1])
    {
        int t = i.a;
        arr[++cnt] = {a1,t,i.val};
        if(!st[t])
        {
            dfs(t);
        }
    }
}

int fa[N];
int find(int a)
{
    return fa[a] == a?a:fa[a] = find(fa[a]);
}

long long res;
void kruskal()
{
    sort(arr+1,arr+1+cnt,cmp);
    for(int i=1;i<=cnt;i++)
    {
        int ta = arr[i].a;int tb = arr[i].b;int tv = arr[i].val;
        int fta = find(ta);
        int ftb = find(tb);
        if(fta!=ftb)
        {
            res+=tv;
            fa[fta] = ftb;
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>h[i];
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(h[a] > h[b])
        {
            vec[a].push_back({b,c});
        }
        else if(h[a] == h[b]){
            vec[b].push_back({a,c});
            vec[a].push_back({b,c});
        }
        else{
            vec[b].push_back({a,c});
        }
    }

    for(int i=1;i<=n;i++)fa[i]=i;

    dfs(1);
    kruskal();
    cout<<pos<<" "<<res;
}