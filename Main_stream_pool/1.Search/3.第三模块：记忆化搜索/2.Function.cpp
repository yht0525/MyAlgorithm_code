#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N = 25;

LL f[N][N][N];

LL dfs(LL a,LL b,LL c)
{
    //First -> research    
    if(a<=0 || b<=0 || c<=0)return 1;
    if(a>20 || b>20 || c>20)return dfs(20,20,20);

    if(f[a][b][c] != 0)return f[a][b][c];

    if(a<b && b<c)
    {
        f[a][b][c] = dfs(a,b,c-1)+dfs(a,b-1,c-1)-dfs(a,b-1,c);
        return f[a][b][c];
    }
    else{
        f[a][b][c] = dfs(a-1,b,c) + dfs(a-1,b-1,c) + dfs(a-1,b,c-1) - dfs(a-1,b-1,c-1);
        return f[a][b][c];
    }
}

int main()
{    
    LL a,b,c;
    while(cin>>a>>b>>c)
    {
        if(a==-1 && b==-1 && c==-1)break;
        printf("w(%lld, %lld, %lld) = %lld\n",  //注意这里要用LLD输出！！！
       a,b,c,dfs(a,b,c));
    }
    return 0;
}