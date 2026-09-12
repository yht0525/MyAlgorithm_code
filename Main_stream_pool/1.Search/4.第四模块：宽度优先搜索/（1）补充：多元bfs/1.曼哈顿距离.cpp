#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N = 2010;
char trr[N][N];
int arr[N][N];
int n,m;

struct node{
    int x;
    int y;
    int epi;
};

int gox[5] = {0,-1,0,1,0};
int goy[5] = {0,0,-1,0,1};

int dis[N][N];

void bfs()
{
    queue<node> qu;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(arr[i][j] == 1)
            {
                qu.push({i,j,0});
                dis[i][j] = 0;
            }
        }
    }
    
    while(qu.size())
    {
        node topp = qu.front();
        qu.pop();
        int ox = topp.x,oy = topp.y;
        
        for(int i=1;i<=4;i++)
        {
            int nox = ox + gox[i],noy = oy + goy[i];
            if(nox>=1 && nox<=n && noy<=m && nox>=1 && dis[nox][noy] == -1)
            {
                dis[nox][noy] = topp.epi+1;
                qu.push({nox,noy,topp.epi+1});
            }
        }
    }
    
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(cin>>trr[i][j],trr[i][j] == '0')
            {
                arr[i][j] = 0;
            }
            else{
                arr[i][j] = 1;
            }
        }
    
    memset(dis,-1,sizeof(dis));
    bfs();
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
}