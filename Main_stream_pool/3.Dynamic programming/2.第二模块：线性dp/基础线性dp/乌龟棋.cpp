#include<iostream>
#include <algorithm>
using namespace std;

const int N1 = 355;
const int N = 45;
int f[N][N][N][N];     //表示用了 a,b,c,d 张 1，2，3，4的卡片走到的 地方的最大权值
int t1,t2,t3,t4;
int n,m;
int arr[N1];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=m;i++)
    {
        int t;cin>>t;
        switch(t)
        {
            case 1:
            t1++;
            break;

            case 2:
            t2++;
            break;

            case 3:
            t3++;
            break;

            case 4:
            t4++;
            break;
        }
    }
    
    for(int i=0;i<=t1;i++)
    {
        for(int j=0;j<=t2;j++)
        {
            for(int x=0;x<=t3;x++)
            {
                for(int y=0;y<=t4;y++)
                {
                    if(i+2*j+3*x+4*y+1 > 4)
                    {
                        int ret = 0;
                        if(i>=1){
                            ret = max(ret,f[i-1][j][x][y]);
                        }
                        if(j>=1){
                            ret = max(ret,f[i][j-1][x][y]);
                        }
                        if(x>=1){
                            ret = max(ret,f[i][j][x-1][y]);
                        }
                        if(y>=1){
                            ret = max(ret,f[i][j][x][y-1]);
                        }
                        f[i][j][x][y] = ret + arr[i+2*j+3*x+4*y+1];
                    }
                    else if(i+2*j+3*x+4*y+1 > 3)
                    {
                        int ret = 0;
                        if(i>=1){
                            ret = max(ret,f[i-1][j][x][y]);
                        }
                        if(j>=1){
                            ret = max(ret,f[i][j-1][x][y]);
                        }
                        if(x>=1){
                            ret = max(ret,f[i][j][x-1][y]);
                        }
                        f[i][j][x][y] = ret + arr[i+2*j+3*x+4*y+1];
                    }
                    else if(i+2*j+3*x+4*y+1 > 2)
                    {
                        int ret = 0;
                        if(i>=1){
                            ret = max(ret,f[i-1][j][x][y]);
                        }
                        if(j>=1){
                            ret = max(ret,f[i][j-1][x][y]);
                        }
                        f[i][j][x][y] = ret + arr[i+2*j+3*x+4*y+1];
                    }
                    else if(i+2*j+3*x+4*y+1 > 1)
                    {
                        int ret = 0;
                        if(i>=1){
                            ret = max(ret,f[i-1][j][x][y]);
                        }
                        f[i][j][x][y] = ret + arr[i+2*j+3*x+4*y+1];
                    }
                    else{
                        f[i][j][x][y] = arr[1];
                    }
                }
            }
        }
    }

    cout<<f[t1][t2][t3][t4];
}