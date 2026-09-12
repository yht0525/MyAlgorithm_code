//AC代码 问题：9*9数独问题

#include<iostream>
using namespace std;
const int N = 20;

bool col[N][N]; bool row[N][N]; bool area[N][N];bool ju=false;
int a[N][N];
int le=0;

int jud(int x,int y)
{
    if(x<=3 && y<=3)return 1;
    else{
        if(x<=3 && y<=6)return 2;
        else{
            if(x<=3 && y<=9)return 3;
            else{
                if(x<=6 && y<=3)return 4;
                else{
                    if(x<=6 && y<=6)return 5;
                    else{
                        if(x<=6 && y<=9)return 6;
                        else{
                            if(x<=9 && y<=3)return 7;
                            else{
                                if(x<=9 && y<=6)return 8;
                                    else{return 9;}
                            }
                        }
                    }
                }
            }
        }
    }
}

void dfs(int cnt,int i,int j)
{
    
    if(ju)return;                                  //如果ju正确直接return，递归出口！！！
    
    if(cnt > le)                                   //填完了！！！
    {
        ju=true;
        return;
    }
    
    if(a[i][j])                                     //如果已经被填过了就换下一个位置
    {
        int ni=i;int nj=j+1;
        if(j==9)
        {
            ni=i+1;
            nj=1;
        }
        dfs(cnt,ni,nj);
        return;
    }

    for(int x=1;x<=9;x++)
    {
        int pos=jud(i,j);
        if( area[pos][x] || row[i][x] || col[j][x])continue;
        else
        {
            a[i][j]=x;
            area[pos][x]=true;row[i][x]=true;col[j][x]=true;
            

            int ni=i;int nj=j+1;
            if(j==9)
            {
                ni=i+1;
                nj=1;
            }
            dfs(cnt+1,ni,nj);

            if(ju)return;                                           //特别注意：填数字型回溯时如果已经完成答案不要清空现场！！！
            a[i][j]=0;
            area[pos][x]=false;row[i][x]=false;col[j][x]=false;
        }
    }
}

int main()
{
    for(int i=1;i<=9;i++)
    for(int j=1;j<=9;j++)
    {
        cin>>a[i][j];
        if(a[i][j])
        {
            int val=a[i][j];
            int pos=jud(i,j);
            col[j][val]=true;
            row[i][val]=true;
            area[pos][val]=true;
        }
        else{
            le++;
        }
    }

    dfs(1,1,1);

    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
        cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}