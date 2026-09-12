#include<iostream>
#include<algorithm>
using namespace std;
//data
const int N = 40; 
int n,w;
int arr[N];
int car[N];
int cot = 1;

bool cmp(int a,int b)
{
    return a > b;
}

//algorithm
int result = 18;
void dfs(int pos)
{
    if(cot >= result)   //这里已经剪掉了cot比result大的情况
    {
        return;
    }
    
    if(pos > n)
    {
        result = cot;
        return;
    }

    for(int i=1;i<=cot;i++)
    {
        if(arr[pos] + car[i] <= w)
        {
            car[i] = arr[pos]+car[i];
        }
        else{
            continue;
        }
        dfs(pos+1);
        car[i]-=arr[pos];
    }

    cot++;
    car[cot]=arr[pos];
    dfs(pos+1);
    car[cot]=0;
    cot--;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>w;
    for(int i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+1+n,cmp);
    dfs(1);
    cout<<result;
}