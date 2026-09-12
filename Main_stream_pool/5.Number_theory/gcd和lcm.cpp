#include<iostream>

using namespace std;

//辗转相除法
//注意： gcd(a,b) + lcm(a,b) == a * b 所以只用算出一个就行
int gcd(int a,int b)
{
      if(!b)return a;
      return gcd(b,a%b);
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
}

//秦九韶大数优化

// #include<iostream>

// using namespace std;

// //辗转相除法
// int gcd(int a,int b)
// {
//       if(!b)return a;
//       return gcd(b,a%b);
// }

// int main()
// {
//     string a;
//     int b;
//     cin>>a>>b;

//     long long pa = 0;
//     for(auto v:a)
//     {
//         pa = pa*10 + v - '0';
//         pa *= b;
//     }
    
//     cout<<gcd(pa,b);
// }