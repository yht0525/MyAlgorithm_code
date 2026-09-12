#include<iostream>
using namespace std;

//data
int t;
const int N  = 1e6;
int fa[N];
int d[N];
int len[N];             //用len数组维护每个根节点的长度

void init()
{
    for(int i=1;i<=30000;i++)
    {
        fa[i] = i;
        d[i] = 0;               //根节点自己到自己的距离是0
        len[i] = 1;
    }
}

int find(int x)
{   
    if(fa[x] == x)return x;

    int t = find(fa[x]);
    d[x] += d[fa[x]];

    return fa[x] = t;
}

void un(int a,int b,int w)
{
    int af = find(a) , bf = find(b);
    if(af != bf)
    {
        fa[bf] = af;
        d[bf] = w;          //这里是头插，所以bf到af的距离就是af所在列的节点个数 ，也就是len[af]
    }
}

int main()
{
    cin>>t;
    init();
    while(t--)
    {
        char ju; int a,b;
        cin>>ju>>a>>b;

        if(ju == 'M')
        {
            int t1 = find(b); int t2 = find(a);
            if(t1!=t2)
            {
                int len1 = len[t1];                 //每次搜索的是根节点的长度 ， 也就是a，b节点所在队列的长度
                int len2 = len[t2];
                un(b,a,len1);
                len[t1] = len1+len2;
            }
        }
        else{
            int af=find(a) , bf=find(b);
            if(af != bf)
            {
                cout<<-1<<endl;
            }
            else{
                int t1 = find(b); int t2 = find(a);
                cout<<abs(d[a] - d[b])-1<<endl;     //注意由于答案是求a，b之间的节点，d表示节点到根节点的距离，要减去1才行
            }
        }
    }
}