#include<iostream>
#include<cstring>
using namespace std;

//通过备忘录实现剪枝
//步骤：    1.创建备忘录
//          2.在返回的时候：把新的值存到备忘录里面
//          3.每次查询在备忘录里面找
const int N = 1e5;
int f[N];

int dfs(int a)
{
    if(f[a] != -1)return f[a];
    if(a == 0 || a == 1)return 1;

    f[a] = dfs(a-2)+dfs(a-1);
    return f[a];
}

int main()
{
    int a;
    cin>>a;

    memset(f,-1,sizeof(f));
    //memset使用（0 ， -1 ， 0x3f）

    cout<<dfs(a);
}