#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5;
vector<int> v[N];

int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}