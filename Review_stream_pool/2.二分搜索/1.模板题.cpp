#include<iostream>
using namespace std;
const int N  = 1e5 + 10;
typedef long long LL;
//data
int t;
LL arr[N];
int m;



int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)cin>>arr[i];
    cin>>m;
    
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        //找最小值
        int left = 1;int right = t;
        while(left < right)
        {
            int mid = (left + right)/2;
            if(arr[mid] < a)
            {
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        int le=1;
        if(left == right)le = left;
        //找最大值
        left = 1;right = t;
        while(left < right)
        {
            int mid = (left+right+1)/2;
            if(arr[mid] > b)
            {
                right = mid-1;
            }
            else{
                left = mid;
            }
        }
        int ri = t;
        if(left == right)ri = left;
        
        //判断并输出
        if(arr[le]<=b && arr[ri]>=a)            //===注意判断条件！===
        {
            cout<<ri-le+1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
}