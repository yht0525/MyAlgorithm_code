#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
//data
const int N = 1e5+10;
int n = 1e5;
int t;
int des[N];

int o,d;    

void bfs()
{
    queue<int> qu;    
    qu.push(o);    
    des[o] = 0;    
    
    while(qu.size())
    {
        int tar = qu.front();
        qu.pop();                                            //一定不要忘了删除集结点！！！
        int x = tar + 1;int y = tar - 1;int z = tar * 2;
        
        if(x <= n && des[x]==-1)
        {
            qu.push(x);
            des[x] = des[tar]+1;
        }
        if(y > 0 && des[y]==-1)
        {
            qu.push(y);
            des[y] = des[tar]+1;
        }
        if(z<=n && des[z]==-1)
        {
            qu.push(z);
            des[z] = des[tar]+1;
        }

        if(x==d || y==d || z==d)
        {
            return;
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>t;
    while(t--)
    {
        //每次计算都要初始化
        memset(des,-1,sizeof(des));
        
        cin>>o>>d;
        bfs();
        cout<<des[d]<<endl;
    }
}