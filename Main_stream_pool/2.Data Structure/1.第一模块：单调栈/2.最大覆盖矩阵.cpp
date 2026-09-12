#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 1e5+10;
int n;
int ret1[N];
int ret2[N];

LL a[N];
LL sum[N];

int main()
{
    int n;
    while(cin>>n,n!=0)
    {
        memset(ret1,0,sizeof(ret1));
        memset(ret2,0,sizeof(ret2));
        for(int i=1;i<=n;i++)cin>>a[i];
        stack<int> st1;
        for(int i=1;i<=n;i++)
        {
            while(st1.size() && a[st1.top()] >= a[i])st1.pop();
            if(st1.size())ret1[i] = st1.top();
            st1.push(i);
        }
        stack<int> st2;
        for(int i=n;i>=1;i--)
        {
            while(st2.size() && a[st2.top()] >= a[i])st2.pop();
            if(st2.size())ret2[i] = st2.top();
            st2.push(i);
        }

        LL result=0;
        for(int i=1;i<=n;i++)
        {
            //四种情况
            if(ret1[i]==0 && ret2[i]!=0){
                sum[i] = a[i] * (ret2[i] - 1); 
            }
            if(ret1[i]!=0 && ret2[i]==0){
                sum[i] = a[i] * (n - ret1[i]);
            }
            if(ret1[i]!=0 && ret2[i]!=0){
                sum[i] = a[i] * (ret2[i] - ret1[i] - 1);
            }
            if(ret1[i]==0 && ret2[i]==0){
                sum[i] = a[i] * n;
            }

            result = max(sum[i],result);
        }
    
        cout<<result<<endl;
    }
}