#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 5050;
int fa[N];
int n,m;

struct node{
    int a,b,val;
}arr[N];

bool cmp(node& a,node& b)
{
    return a.val < b.val;
}

int find(int a)
{
    return fa[a] == a?a: fa[a] = find(fa[a]);
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>arr[i].a>>arr[i].b>>arr[i].val;
    }

    for(int i=1;i<=n;i++)
    {
        fa[i] = i;
    }

    sort(arr+1 , arr+1+m ,cmp);
    int cnt = 0;
    int ret = 0;
    for(int i=1;i<=m;i++)
    {
        int ta = arr[i].a;
        int tb = arr[i].b;
        int tv = arr[i].val;

        int fta = find(ta),ftb = find(tb);
        if(fta != ftb){
            ret += tv;
            cnt++;
            fa[fta] = ftb;        //把父节点挂到b上面
        } 
    }

    if(cnt == n-1){
        cout<<ret<<endl;
    }
    else{
        cout<<"orz"<<endl;
    }
}