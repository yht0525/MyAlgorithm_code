#include<iostream>
using namespace std;

const int N = 1e5;
int a[N];
int n;
int tol;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        tol+=a[i];
    }

    int left = 1;
    int right = 1;


    int ret = 0;
    int sum = 0;

    while( right<=n )
    {
        sum+=a[right++];
        while(sum*2 >= tol)
        {
            ret = max(ret,tol - sum);
            sum-=a[left++];
        }
        ret = max(ret,sum);
    }

    cout<<ret;

}

// #include<iostream>
// using namespace std;

// const int N = 1e5+10;
// int ret = 0;
// int n;
// int a[N];
// int sum;

// int main()
// {
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         sum+=a[i];
//     }
    
//     int left = 1;
//     int right = 1;
//     int t = 0;
//     while(right<=n)
//     {
//         t+=a[right];
//         while(2*t >= sum)
//         {
//             ret = max(sum-t,ret);
//             t-=a[left++];
//         }
//         ret = max(ret,t);
//         right++;
//     }
    
//     cout<<ret;
// }