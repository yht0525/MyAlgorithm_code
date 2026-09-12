#include<iostream>
#include<algorithm>
using namespace std;

const int N = 25;
int f[N][N][N];    //s:一共走s步 l1:第一个走的y轴 l2:第二走的y轴
int a[N][N];

int n;

int main()
{
    cin>>n;
    int a1,b,c;
    while(cin>>a1>>b>>c,(a1!=0 && b!=0))
    {
        a[a1][b] = c;
    }

    f[2][1][1] = 1;
    for(int i=2;i<=2*n;i++)
    {
        for(int x=1;x<i;x++)
        {
            for(int y=1;y<i;y++)
            {
                //当前位置的获取
                int y1 = x;
                int y2 = y;
                int x1 = i-y1;
                int x2 = i-y2;
                for(int t=0;t<=1;t++)
                {
                    f[i][x][y] = max({f[i-1][x-1][y],f[i-1][x][y-1],f[i-1][x-1][y-1],f[i-1][x][y]});
                }
                //最后补上
                if(y1!=y2 || x1!=x2)f[i][x][y] += a[x1][y1] + a[x2][y2];
                else{
                    f[i][x][y] += a[x1][y1];
                }
            }
        }
    }
    cout<<f[n*2][n][n];
}