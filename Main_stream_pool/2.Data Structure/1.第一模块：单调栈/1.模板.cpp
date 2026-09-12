#include<iostream>
#include<stack>
using namespace std;

const int N = 1e5;
int n;
int a[N];

//模板：距离一个数字左边（右边）最近的且比他大（小）的数字
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    int ret[n];
    stack<int> st;
    for(int i=1;i<=n;i++)                           //改变遍历顺序可以改变方向
    {    
        while(st.size() && a[st.top()] <= a[i])     //改变 ‘<’ 为 ‘>’ 即可
        {
            st.pop();
        }

        if(st.size())
        {
            ret[i] = st.top();
        }
        st.push(i);
    }

    for(int i=1;i<=n;i++)
    {
        cout<<ret[i]<<" ";
    }
}