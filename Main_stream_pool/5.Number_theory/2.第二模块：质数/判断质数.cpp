//最简单

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int n;
int f[110];
vector<int> v;

bool isprim(int a)
{
    if(a<=1)return false;

    for(int i=2;i<=sqrt(a);i++)
    {
        if(a%i == 0)return false;
    }

    return true;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        if(isprim(t)){
            v.push_back(t);
        }
    }
    for(int i:v)
    {
        cout<<i<<" ";
    }
}