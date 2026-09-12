#include<iostream>
#include<unordered_map>
#include<cstring>
#include<algorithm>
using namespace std;

//离散化
const int N = 2e5+10;
int a[N];
int dis[N];
int pos;

//并查集
int n,t;
int fa[N];

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void un(int a,int b)
{
    int af = find(a);
    int bf = find(b);
    fa[bf] = af;
}

//data
int jud[N];
int le[N];
int ri[N];

int main()
{
    cin>>t;
    while(t--)
    {
        //接收数据
        unordered_map<int,int> mp;
        cin>>n;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            int q,b,c;
            cin>>q>>b>>c;

            le[i] = q; ri[i] = b;
            
            cnt++;
            a[cnt] = q;
            dis[cnt] = q;
            cnt++;
            a[cnt] = b;
            dis[cnt] = b;
            
            jud[i] = c;
        }
        
        //离散化
        sort(dis+1,dis+1+2*n);
        int cnt1 = 0;
        for(int i=1;i<=2*n;i++)
        {
            int x = a[i];
            if(mp.count(x))continue;
            cnt1++;
            mp[x] = cnt1;
        }// mp[x(就是数组里面的元素)] -> 对应为 1~cnt1里面的数 

        //处理数据
        for(int i=1;i<=cnt1;i++)
        {
            fa[i] = i;
        }

        bool j = true;
        
        for(int i=1;i<=n;i++)
        {
            if(jud[i])
            {
                un(mp[le[i]],mp[ri[i]]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(!jud[i])
            {
                int t1 = find(mp[le[i]]);
                int t2 = find(mp[ri[i]]);
                if(t1 == t2)
                {
                    cout<<"NO"<<endl;
                    j=false;
                    break;
                }
            }
        }
        if(j)cout<<"YES"<<endl;
    }
}