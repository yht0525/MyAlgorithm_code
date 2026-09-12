#include<iostream>
#include<cstring>
using namespace std;

const int N = 3e6+10;
int idx=0;
int tree[N][63],p[N];

int get_num(char a)
{
    if(a<='Z' && a>='A')
    {
        return 1+a-'A';
    }
    else if(a<='z' && a>='a'){
        return 27+a-'a';
    }
    else{
        return 53+a-'0';
    }
}

void insert(string &a)
{
    int cur = 0;
    p[cur]++;
    for(auto ch:a)
    {
        int t = get_num(ch);
        if(tree[cur][t] == 0)tree[cur][t] = ++idx;
        cur = tree[cur][t];
        p[cur]++;
    }
}

int find_pre(string &a)
{
    int cur = 0;
    for(auto ch:a)
    {
        int t = get_num(ch);
        if(tree[cur][t] == 0)return 0;
        cur = tree[cur][t];
    }
    return p[cur];
}

int m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m;
    while(m--)
    {
        
        for(int i=0;i<=idx;i++)         //不能用memset，数组开太大，会超时！！！
        {
            for(int j=1;j<=62;j++)
            {
                tree[i][j] = 0;
            }
        }
        for(int i=1;i<=idx;i++)
        {
            p[i] = 0;
        }
        
        idx = 0;
        int a,b;
        cin>>a>>b;
        while(a--)
        {
            string t;
            cin>>t;
            insert(t);
        }
        while(b--)
        {
            string t;
            cin>>t;
            cout<<find_pre(t)<<'\n';
        }
    }
}