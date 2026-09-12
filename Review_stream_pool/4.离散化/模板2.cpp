//第二个模板： 排序+哈希表(这个简单！！！)
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

const int N = 1e5+10;

int n;
int tmp[N];
int a[N];
int pos = 0;

int main()
{
    unordered_map<int,int> mp;

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        tmp[++pos] = a[i];
    }

    //排序+去重
    sort(tmp + 1,tmp + 1 + pos);
    int cnt = 0;
    for(int i=1;i<=pos;i++)
    {
        int x = tmp[i];
        if(mp.count(x))continue;
        mp[x] = (++cnt);
    }


    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" is="<<mp[a[i]]<<endl;
    }
}
