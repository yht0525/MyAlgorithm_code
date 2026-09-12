#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

//data
const int N = 100;
char trr[N][N];
int arr[N][N];
int n,m;
int result = 0;

struct node{
    int x;
    int y;
    int epi;
};

int st[N][N];

int gox[4] = {-1,0,1,0};
int goy[4] = {0,-1,0,1};

void bfs(int x,int y)
{
    if(arr[x][y] == 1)
    {
        result=0;
        return;
    }
    
    queue<node> qu;
    node ori = {x,y,0};
    qu.push(ori);
    st[x][y] = 1;
    
    while(qu.size())
    {
        node topp = qu.front();
        qu.pop();
        int ox = topp.x; int oy = topp.y;
        
        for(int i=0;i<=3;i++)
        {
            int nox = ox + gox[i];
            int noy = oy + goy[i];
            if(!st[nox][noy] && nox<n && nox>=0 && noy>=0 && noy<m)
            {
                if(arr[nox][noy] == 1){
                    result = topp.epi + 1;
                    return;
                }
                node tmp = {nox,noy,topp.epi + 1};
                qu.push(tmp);
                st[nox][noy] = 1;
            }
        }
    }
}


int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>trr[i][j];
            if(trr[i][j] == '0')arr[i][j] = 0;    //连起来的要用字符串识别
            else{
                arr[i][j] = 1;
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            memset(st,0,sizeof(st));
            result = 0;
            bfs(i,j);
            cout<<result<<" ";
        }
        cout<<endl;
    }
}