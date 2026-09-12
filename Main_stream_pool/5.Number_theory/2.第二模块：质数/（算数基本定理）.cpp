//任何一个大于1的自然数n，都可以分解为有限的质数相乘
//试除法分解质因数
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const int N = 1e5+10;

int n,n1,n2;
int cnt[N];
vector<int> v;

void deprime()
{
    for(int x=2;x <= n;x++)
    {
        int k = 0;
        while(n1 % x==0)
        {
            n1 /= x;
            k++;
        }
        if(k!=0){v.push_back(x);n2 = x;}
        cnt[x] += k;
    }

    if(n1!=1)
    {
        cnt[n1] += 1;
        v.push_back(n1);
        n2 = n1;
    }
}

int main()
{
    int k;
    cin>>n1;
    k = n1;
    n = sqrt(n1);

    deprime();

    cout<<k<<" = ";
    for(int i:v)
    {
        if(i!=n2)cout<<i<<"^"<<cnt[i]<<"*";
        else{
            cout<<i<<"^"<<cnt[i];
        }
    }
}
