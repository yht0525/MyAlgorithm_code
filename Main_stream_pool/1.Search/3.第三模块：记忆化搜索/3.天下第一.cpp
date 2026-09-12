#include<iostream>
#include<cstring>
using namespace std;
//data
const int N = 1e4;
int p;
int T;
char f[N][N];

//algorithm
char dfs(int x,int y)
{
    if(x == 0)return f[x][y] = '1';
    if(y == 0)return f[x][y] = '2';
    
    if((int)f[x][y] > (int)'0')return f[x][y];
    else if(f[x][y] == '0')
    {
        f[x][y] = (char)(47);
    }
    else
    {
        return f[x][y] = '3';
    }

    return f[x][y] = dfs((x+y)%p , (x+2*y)%p);      //两部合成一部（一个周期）
}

int main()
{
    memset(f,'0',sizeof(f));
    cin>>T>>p;
    while(T--)
    {
        int a,b;cin>>a>>b;
        switch(dfs(a,b))
        {
        case '1':
        cout<<1<<endl;
        break;
        case '2':
        cout<<2<<endl;
        break;
        case '3':
        cout<<"error"<<endl;
        break;
        }
    }
    return 0;
}