#include<iostream>
using namespace std;
const int N = 1e5+5;
int n;
int arr[N];
int tree[N*32][2];
int ret = 0;
int idx;

void insert(int num)
{
    int cur = 0;
    for(int i=31;i>=0;i--)
    {
        int t = ((num >> i) & 1);
        if(tree[cur][t] == 0)tree[cur][t] = ++idx;
        cur = tree[cur][t];
    }
}

int find(int num)
{
    int cur = 0;
    ret = 0;
    for(int i=31;i>=0;i--)
    {
        int t = ((num >> i) & 1);
        int t1 = t^1;
        
        if(tree[cur][t1])
        {
            ret = ret | (1 << i);
            cur = tree[cur][t1];
        }
        else{
            cur = tree[cur][t];
        }
    }
    return ret;
}


int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        insert(arr[i]);
    }

    int cot=0;
    
    for(int i=1;i<=n;i++)
    {
        cot = max(cot,find(arr[i]));
    }
    
    cout<<cot;
}