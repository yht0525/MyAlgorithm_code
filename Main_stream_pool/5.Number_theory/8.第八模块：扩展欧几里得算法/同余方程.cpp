#include<iostream>
#include<cmath>
using namespace std;

typedef long long LL;

//扩展欧几里得
LL E(int a,int b,LL &x,LL &y)
{
        //出口
        if(b == 0)
        {
            x = 1;
            y = 0;
            return a;
        }
        LL a1 = b;
        LL b1 = a%b;
        LL x1,y1;
        LL d = E(a1,b1,x1,y1);
        x = y1;
        y = (x1 - (a/b) * y1);

        return d;
}

//同余方程  a*x == b(mod m) 同余
//         可以转化为： a*x + m*y = b
//         同理： 如果b == 1,那x就是a在mod m 下的乘法逆元，只需要保证gcd(a,m) == 1即可


int main()
{


}

// 重点是 找到同余公式 ： 注意： 最后形式上的a * x + b * y = c中 a,b均为正数，c可为负数
// #include<iostream>
// #include<cmath>
// using namespace std;
// typedef long long LL;

// LL x,y,m,n,L;

// bool jud()
// {
//     if(m == n){
//         return false;    
//     }
//     else{
//         return true;
//     }
// }

// LL E(LL a,LL b,LL &x,LL &y)
// {
//     if(b == 0){
//         x = 1;
//         y = 0;
//         return a;
//     }
//     LL a1,b1,x1,y1;
//     a1 = b;
//     b1 = a%b;
//     LL d = E(a1,b1,x1,y1);
//     x = y1;
//     y = (x1 - (a/b)*y1);

//     return d;
// }

// int main()
// {
//     cin>>x>>y>>m>>n>>L;    
    
//     if(!jud()){
//         cout<<"Impossible";
//     }
//     else{
//         LL dL = (x-y);
//         LL dv = (m-n);
        
//         if(dv < 0){
//             dv = -dv;
//             dL = -dL;
//         }
//         LL x1,y1;
//         LL d = E(dv,L,x1,y1);
        
//         if(abs(dL) % d != 0){
//             cout<<"Impossible";
//         }
//         else{
//             int k = L/d;
//             cout<<k<<endl;
//             cout<<x1<<endl;
//             cout<<(x1 % k + k)%k;
//         }
//     }    
// }