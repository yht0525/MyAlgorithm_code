#include<iostream>
using namespace std;
const int N = 1e8,P = 13331;
typedef unsigned long long ULL;
string s;
ULL f[N];
ULL p[N];
int len;

//data
int m;

void init()
{
    f[0] = 0; p[0] = 1;
    for(int i=1;i<=len;i++)
    {
        f[i] = f[i-1] * P + s[i-1];
        p[i] = p[i-1] * P;
    }
}

ULL get(int l,int r)
{
   return f[r] - f[l-1] * p[r-l+1]; 
}

int main()
{
    cin>>s;
    cin>>m;
    len = s.length();
    init();             //注意加上初始化函数
    while(m--)
    {
        int l1,l2,r1,r2;
        cin>>l1>>r1>>l2>>r2;
        ULL t1,t2;
        t1 = get(l1,r1);
        t2 = get(l2,r2);
        if(t1 == t2)
        {
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}