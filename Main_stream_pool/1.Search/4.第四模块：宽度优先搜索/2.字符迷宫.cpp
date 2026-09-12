#include<queue>
#include<cstring>
#include<iostream>
using namespace std;
const int N = 100;

int ox,oy;

int gox[4] = {-1,0,1,0};
int goy[4] = {0,-1,0,1};

int n,m;
char arr[N][N];
int brr[N][N];

int st[N][N];

struct node{
    int x;
    int y;
    int episode;
};

void bfs()
{
    queue<node> qu;
    node a = {ox,oy,0};
    qu.push(a);
    st[ox][oy] = 1;
    
    while(qu.size()!=0)
    {
        node ori = qu.front();
        qu.pop();
        
        for(int i=0;i<=3;i++)
        {
            int nowx = ori.x + gox[i];
            int nowy = ori.y + goy[i];
            
            if(st[nowx][nowy]!=1 && (nowx <= n && nowy <=m) && (nowx >= 1 && nowy >= 1) && (arr[nowx][nowy] != '*'))
            {
                node tmp = {nowx,nowy,ori.episode+1};
                if(arr[nowx][nowy] == 'e'){
                    brr[nowx][nowy] = ori.episode + 1;
                    continue;
                }
                brr[nowx][nowy] = ori.episode + 1;
                qu.push(tmp);
                st[nowx][nowy] = 1;
            }
        }
    }
}




int main()
{
    memset(brr,0,sizeof(brr));
    int cot = 0;
    int result = 1000;
    
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        cin>>arr[i][j];
        if(arr[i][j] == 'k'){
            ox = i;
            oy = j;
        }
    }
    
    bfs();
    
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        if(arr[i][j] == 'e' && brr[i][j] != 0)
        {
            cot++;
            result = min(result,brr[i][j]);
        }
    }
    cout<<cot<<" "<<result;
}