#include<iostream>
#include<deque>
using namespace std;

const int N = 1e6+10;
int n,k;
int a[N];
int cot1;
int cot;
int ret[N];
int ret1[N];
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    //最大值
    deque<int> dq;
    for(int i=1;i<=n;i++)
    {
        //维护队列
        while(dq.size() && a[dq.back()] <= a[i])
        {
            dq.pop_back();
        }
        while(dq.size() && dq.front() <= i-k)dq.pop_front();
        dq.push_back(i);                        //注意：滑动窗口当前值与结果有影响，先添加
        if(i>=k){
            ret[++cot] = dq.front();
        }
    }

    //最小值
    deque<int> dq1;
    for(int i=1;i<=n;i++)
    {
        //维护队列
        while(dq1.size() && a[dq1.back()] >= a[i])
        {
            dq1.pop_back();
        }
        while(dq1.size() && dq1.front() <= i-k)dq1.pop_front();
        dq1.push_back(i);
        if(i>=k){
            ret1[++cot1] = dq1.front();
        }
    }


    for(int i=1;i<=cot1;i++)cout<<a[ret1[i]]<<" ";
    cout<<endl;
    for(int i=1;i<=cot;i++)cout<<a[ret[i]]<<" ";       
}