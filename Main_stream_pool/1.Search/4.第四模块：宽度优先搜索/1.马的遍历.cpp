#include<iostream>
#include<queue>
using namespace std;
//data
const int N = 450;
int f[N][N];
int rows,columns;
int ox,oy;

//algorithm
int result[N][N];
int st[N][N];

int gox[8] = {-2,-1,1,2,2,1,-1,-2};
int goy[8] = {-1,-2,-2,-1,1,2,2,1};

struct node{
    int x;
    int y;
    int val;
};

void bfs()
{
    node o = {ox,oy,0};
    queue<node> qu;
    qu.push(o);
    st[ox][oy] = 1;
    result[ox][oy] = 0;
    
    int cot = 1;
    
    while(qu.size())
    {
        node topp = qu.front();
        qu.pop();

        for(int i=0;i<8;i++)
        {
            int nowx = topp.x + gox[i];                            //ai改正，修复了定义变量的问题
            int nowy = topp.y + goy[i];
            if(nowx < 1 || nowx > rows || nowy < 1 || nowy > columns)
            {
                continue;
            }
            else 
            {
                if(!st[nowx][nowy])
                {
                    node neww = {nowx,nowy,topp.val + 1};                //ai改正，修复了cot问题
                    qu.push(neww);
                    result[nowx][nowy] = topp.val + 1;
                    st[nowx][nowy] = 1;
                }
            }
        }
    }
}

int main()
{
    cin>>rows>>columns>>ox>>oy;
    bfs();

    
    for(int i=1;i<=rows;i++)
    {
    for(int j=1;j<=columns;j++)
    {
        if((i!=ox || j!=oy) && !result[i][j])
        {
            cout<<-1<<" ";
        }
        else{
            cout<<result[i][j]<<" ";
        }
    }
    cout<<endl;
    }
    
}