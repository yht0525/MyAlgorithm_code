#include<iostream>

//第二类问题：  ex   1.n个节点，一共可以构造处多少二叉树？
//                  2.圆上有2n个点，将每个点亮亮连接，令每两条线不相交，有几种方法？
//                  3.凸 n+2 边形用n-2条对角线分成不重叠的三角形，有几种方法？
//              注意这里面的节点是不带编号的，只要结构不一样就是不同

int main()
{
    
}

//高精度除法和加法

// #include<iostream>
// using namespace std;

// const int N = 500+10;
// typedef long long LL;

// int d[N];

// void muti(int d[] , int k)
// {
//     int upnum = 0;
//     for(int i=0;i<=N-1;i++)
//     {
//         int l = upnum + d[i] * k;
//         upnum = l/10;
//         d[i] = l%10;
//     }
// }

// void divi(int d[], int k)
// {
//     int bow = 0;
//     for(int i=N-1;i>=0;i--)
//     {
//         int l = (bow + d[i]);
//         d[i] = l/k;
//         bow = l%k * 10;
//     }
// }
// int n;
// // void mutiTen(int d[])
// // {
// //     for(int i=N-1;i>=1;i--)
// //     {
// //         d[i] = d[i-1];
// //     }
// //     d[0] = 0;
// // }
// void get()
// {
//     d[0] = 1;
//     for(int i=2;i<=n;i++)
//     {
//         muti(d,4*i - 2);  
//         divi(d,i+1);
//     }
// }



// int main()
// {
//     cin>>n;
    
//     get();
    
//     bool jue = false;
//     for(int i=N-1;i>=0;i--)
//     {
//         if(d[i]!=0){
//             jue = true;
//         }
//         if(jue)printf("%d",d[i]);
//     }
    
//     if(!jue)printf("0");
// }