#include<iostream>
#include<cstring>
using namespace std;

//data
const int N = 101;

//algorithm
int gox[4] = {-1,0,1,0};
int goy[4] = {0,1,0,-1};
int arr[N][N];
int rows,columns;
int f[N][N];

int dfs(int x,int y)
{
    if(f[x][y])return f[x][y];

    //搜寻四个方向的dfs()

    int temp = 0;int result = 0;
    
    for(int i=0;i<4;i++)
    {
        //越界不行
        int nowx = x + gox[i];
        int nowy = y + goy[i];
        if(nowx < 1 || nowy < 1 || nowx > rows || nowy > columns)
        {
            continue;
        }
        
        if(arr[nowx][nowy] < arr[x][y]){
            temp = dfs(nowx,nowy);
        }
        else{
            continue;
        }

        result = max(result ,1+temp);
    }

    return f[x][y] = result;
}

int main()
{
    cin>>rows>>columns;
    memset(f,0,sizeof(f));
    for(int i=1;i<=rows;i++)
    for(int j=1;j<=columns;j++)
    {
        cin>>arr[i][j];
    }

    int ret = 0;
    for(int i=1;i<=rows;i++)
        for(int j=1;j<=columns;j++)
        {
            ret = max(ret,1+dfs(i,j));
        }
    
    cout<<ret;
}