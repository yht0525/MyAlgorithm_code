#include<iostream>
#include<cstring>
using namespace std;

const int N = 10;
int n;
int a[N][N];
int a1[N][N];
int t;

void change(int x,int y)
{
    a1[x][y] ^= 1;
    a1[x+1][y] ^= 1;
    a1[x-1][y] ^= 1;
    a1[x][y-1] ^= 1;
    a1[x][y+1] ^= 1;
    ++t;
}

int main()
{
     cin>>n;
    while(n--)
    {
        //识别数据
        for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
        {
            char t;
            cin>>t;
            a[i][j] = t-'0';
        }

        //二进制枚举所有办法，找到最短步骤
        int ret = 1000;
        for(int i=0;i<=31;i++)
        {
            t = 0;
            memcpy(a1,a,sizeof(a1));
            //只取决于第一行的改变
            for(int j=0;j<5;j++)
            {
                if(((i >> j) & 1) == 1)
                {
                    change(1,j+1);
                }
            }
            //后几行的循环
            for(int x=2;x<=5;x++)
            {
                for(int y=1;y<=5;y++)
                {
                    if(a1[x-1][y] == 0)
                    {
                        change(x,y);
                    }
                }
            }
            bool jud = true;
            for(int x=1;x<=5;x++)
            {
                if(a1[5][x] == 0)jud = false;
            }
            if(jud){
                ret = min(ret,t);                   //注意：对于ret，当没有合适方案时不要修改，此时ret==1000！！！
            }
        }
        
        //根据结果输出
        if(ret > 6 || ret==1000){
            cout<<-1<<endl;
        }
        else{
            cout<<ret<<endl;
        }
    }
}