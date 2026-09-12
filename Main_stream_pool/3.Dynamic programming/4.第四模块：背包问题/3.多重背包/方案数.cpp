#include<iostream>
#include<cstring>
using namespace std;

const int N = 205;
int mod = 1e6+7;
long long f[N][N];        //表示在[1,i]这几种花里面选，在不超过j盆的条件下的最大种类    
int n,m;
int num[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
    }

    f[0][0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)                   //注意：方案数一定要从0开始！！！
        {
            f[i][j] += f[i-1][j]%mod;
            for(int x=1;x<=num[i];x++)
            { 
                if(j-x >= 0){
                    f[i][j] += f[i-1][j-x]%mod;
                }
                else{
                    break;
                }
            }
        }
    }

    cout<<(f[n][m]%mod);
}

// #include<iostream>
// #include<cstring>
// using namespace std;

// const int N = 205;
// int mod = 1e6+7;
// long long f[N];        //表示在[1,i]这几种花里面选，在不超过j盆的条件下的最大种类    
// int n,m;
// int num[N];

// int main()
// {
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>num[i];
//     }

//     f[0] = 1;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=m;j>=0;j--)
//         {
//             for(int x=1;x<=num[i];x++)
//             { 
//                 if(j-x >= 0){
//                     f[j] = (f[j]+f[j-x])%mod;
//                 }
//                 else{
//                     break;
//                 }
//             }
//         }
//     }

//     cout<<(f[m]%mod);
// }
// 空间优化版 --> 注意不能用 ‘+=’ 进行累加，用 = 直接赋值！！！