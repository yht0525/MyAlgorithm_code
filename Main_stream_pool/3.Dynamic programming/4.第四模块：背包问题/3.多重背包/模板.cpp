#include<iostream>
using namespace std;

const int N = 1e3;
int n,T;

int f[N][N];    //表示从【1，i】里面选物品，在不超过j的重量下最大的价值
int w[N],v[N],num[N];


int main()
{
    cin>>n>>T;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i]>>w[i]>>v[i];
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=T;j++)
        {
            f[i][j] = f[i-1][j];
            for(int x=1;x<=num[i];x++)
            {
                if(j>=x*w[i])f[i][j] = max(f[i][j],f[i-1][j-x*w[i]]+x*v[i]);
                else{
                    break;
                }
            }
        }
    }
    
    cout<<f[n][T];
}

//空间优化版本：注意遍历顺序！！！

// #include<iostream>
// using namespace std;

// const int N = 1e3;
// int n,T;

// int f[N];    //表示从【1，i】里面选物品，在不超过j的重量下最大的价值
// int w[N],v[N],num[N];


// int main()
// {
//     cin>>n>>T;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>num[i]>>w[i]>>v[i];
//     }
    
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=T;j>=1;j--)
//         {
//             for(int x=1;x<=num[i];x++)
//             {
//                 if(j>=x*w[i])f[j] = max(f[j],f[j-x*w[i]]+x*v[i]);
//                 else{
//                     break;
//                 }
//             }
//         }
//     }
    
//     cout<<f[T];
// }