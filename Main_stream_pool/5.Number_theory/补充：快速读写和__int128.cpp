#include<iostream>
using namespace std;
typedef __int128 LL;            //只能在GCC和linux上使用

//快速读写
LL getLL()
{
    LL ret = 0;
    int flag = 1;
    char x = getchar();
    while(x>'9' || x<'0')
    {
        if(x == '-')flag = -1;
        x = getchar();
    }

    while(x<='9' && x>='0')
    {
        ret = ret*10 + x-'0';
        x = getchar();
    }

    return flag*ret;
}

void print(LL x)
{
    if(x<0){
        x = -x;
        putchar('-');
    }

    if(x/10 > 0)print(x/10);
    putchar(x%10 + '0');
}

int main()
{
    // LL t = getLL();
    // LL sum = 0;
    // while(t--)
    // {
    //     LL t = getLL();
    //     sum += t;
    // }
    // print(sum);
}