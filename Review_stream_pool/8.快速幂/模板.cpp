#include<iostream>
#include<cmath>
using namespace std;

const int MOD = 10009;
const int N = 1e5+10;

// 倍增 (二进制) "复杂版"
// int a,b;
// int m;
// int arr[N];
// int st[N];
// int maxn;

// void get_arr()
// {
//     int cnt = 0;
//     int t = a;
//     int k = maxn-1;
//     while(k--)
//     {
//         t *= t;
//         arr[++cnt] = t;
//     }
//     arr[0] = a;
// }

// void get_biary()
// {
//     int t = a;
//     int cnt = 0;
//     while(b)
//     {    
//         if((b & 1) == 1)
//         {
//             st[cnt] = 1;
//         }
//         b = (b>>1);
//         cnt++;
//     }
//     maxn = cnt;
// }


//简版
int a,b,m;

long long get_binary()
{
    long long ant = 1;
    while(b)
    {
        if((b & 1) == 1)
        {
            ant *= a % m;
        }

        a = (a * a)%m;
        b = (b>>1);
    }
    return ant;
}



int main()
{
    cin>>a>>b>>m;
    cout<<get_binary();
}