#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ULL;
const int N = 1e5;    ULL p = 13331;
ULL ret=0; int len;
ULL get(string a)
{
    for(int i=1;i<=len;i++)
    {
        ret = ret*p + a[i-1];
    }
    return ret;
}

int n;
ULL arr[N];

int main()
{
    cin>>n;
    int cot = 0;
    while(n--)
    {
        string t;
        cin>>t;
        //初始化：
        len = t.length();
        ret = 0;
        //计算hash值
        ULL result = get(t);
        arr[++cot] = result;
    }
    
    sort(arr+1,arr+cot+1);

    int ret1 = 1;
    ULL k = arr[1];
    for(int i=2;i<=cot;i++)
    {
        if(arr[i]!=k){
            ret1++;
            k=arr[i];
        }
    }
    cout<<ret1;
}