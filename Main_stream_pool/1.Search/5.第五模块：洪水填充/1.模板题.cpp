#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
//data
const int N = 105;
int n,m;
char arr[N][N];
bool st[N][N];
int cot=0;
struct node{
    int x;
    int y;
    int epi;
};

int gox[8] = {-1,-1,0,1,1,1,0,-1};
int goy[8] = {0,-1,-1,-1,0,1,1,1};

//遍历全部的w，每次到达打上标记
void bfs(int x,int y)
{
    //是1就退出
    if(st[x][y])return;
    else{
        cot++;
        queue<node> qu;
        qu.push({x,y,0});
        st[x][y] = true;
        
        while(qu.size())
        {
            node topp = qu.front();
            qu.pop();
            int ox = topp.x,oy = topp.y;
            int e = topp.epi;

            for(int i=0;i<=7;i++)
            {
                int nox = ox+gox[i],noy = oy+goy[i];
                if(nox<=n && nox>0 && noy<=m && noy>0 && !st[nox][noy] && arr[nox][noy]=='W')
                {
                    qu.push({nox,noy,e+1});
                    st[nox][noy] = true;
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>arr[i][j];
        }
    }

    memset(st,0,sizeof(st));
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(arr[i][j] == 'W')bfs(i,j);
        }
    }

    cout<<cot;
}