#include<iostream>
#include<cstring>
using namespace std;

const int N = 1005;
int f[N][N];
int dp[N][N];
int n;

int main()
{
    cin>>n;
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>f[i][j];
        }
    }

    dp[1][1] = f[1][1];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j] = f[i][j] + max(dp[i-1][j-1],dp[i-1][j]); 
        }
    }

    int ret = 0;
    for(int i=1;i<=n;i++)
    {
        ret = max(ret,dp[n][i]);
    }
    cout<<ret;
}

// ==========空间优化==========
// #include<iostream>
// #include<cstring>
// using namespace std;

// const int N = 1005;
// int f[N][N];
// int dp[N];
// int n;

// int main()
// {
//     cin>>n;
//     memset(f,0,sizeof(f));
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=i;j++)
//         {
//             cin>>f[i][j];
//         }
//     }

//     dp[1] = 0;
//     for(int i=1;i<=n;i++)
//     for(int j=i;j>=1;j--)
//     {
//         dp[j] = f[i][j] + max(dp[j-1],dp[j]); 
//     }

//     int ret = 0;
//     for(int i=1;i<=n;i++)
//     {
//         ret = max(ret,dp[i]);
//     }
//     cout<<ret;
// }