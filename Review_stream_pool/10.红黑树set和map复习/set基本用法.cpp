#include<iostream>
#include<set>
using namespace std;

int a[] = {1,34,4234,4,54,123,1233,12233,1233};

int main()
{
    // set<int> st;
    multiset<int> mt;
    //遍历

    //实现增删改查
    //增
    for(auto i:a)
    {
        // st.insert(i);
        mt.insert(i);
    }

    // for(auto i:st)
    // {
    //     cout<<i;
    // }

    for(auto i:mt)
    {
        cout<<i;
    }
    if(mt.count(1))cout<<"True";

    //删
    cout<<mt.size();
    mt.erase(1);
    cout<<mt.size();
    for(auto i:mt)
    {
        cout<<i;
    }

    //查找
    if(mt.count(1))cout<<"True";

    
    //lower_bound（大于等于的） upper_bound（大于的）
    // cout<<mt.lower_bound(5);

    auto it = mt.upper_bound(5);
    if(it != mt.begin())--it;
    cout<<*it;
}