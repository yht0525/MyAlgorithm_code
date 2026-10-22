#include<iostream>
using namespace std;

//公式 lcm = a/gcd(a,b) *  b
//可以递归求很多个数的lcm

//问题：求不被 x,y,z,... 整除的数的个数

typedef unsigned long long ULL;
const int N = 25;

//64位无符号 -> unsigned long long 
ULL pri[N];
int n;
ULL m;


int main()
{
    //二进制枚举
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)cin>>pri[i];
        
    int tn = (1<<n) - 1; 
    ULL ret = 0;
    
    for(int i=1;i<=tn;i++)
    {
        //一次选择
        int cnt = 0;
        int ti = i;
        ULL total = 1;
        for(int j=0;j<n;j++)
        {
            if(((ti >> j)&1) == 1){
                total*=pri[j+1];
                cnt++;
            }
        }
        if(cnt%2 == 0){
            //偶数位负数
            ret -= (m/total);
        }
        else{
            ret += m/total;
        }
    }
    
    cout<<ret;
}