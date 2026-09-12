#include<iostream>
using namespace std;
const int N = 1e5;
int e[2*N];int ne[2*N];int h[N];
int id=0;

int n;

void add(int a,int b)
{
    id++;
    e[id]=b;
    ne[id]=h[a];
    h[a]=id;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
}