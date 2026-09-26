#include<iostream>
#include<map>
using namespace std;
const int N = 1e5+10;

struct node{
    int val;
    int x;
    int y;

    bool operator <(const node& other)const{
        return val < other.val;
    }

    // int operator[](const node& other){
    //      return other.val;
    //  }
}arr[N];

// class A{
//     int operator[](const node& other){
//         return other.val;
//     }
// };

int main()
{
    // 注意map重载了【】，但是multimap没有
    // map<node,int> mp;       //key ，val会按照第一个关键字进行排序

    // int n;
    // cin>>n;

    // //[] 重载 -> 和insert功能一样，返回*val
    // for(int i=1;i<=n;i++)
    // {
    //     mp[{i,1,1}] = 1;
    // }

    multimap<node,int> mp;
    node t1 = {1,1,1};
    node t2 = {2,1,1};

    mp.insert({t1,1});
    mp.insert({t2,1});

    node *tmp = &t1; 
    cout<<tmp;
    if(mp.count(*tmp)){
        cout<<"Exist"<<endl;
    }
    // mp.erase(*tmp);
    // if(mp.count(*tmp)){
    //     cout<<"Exist"<<endl;
    // }

    auto it = mp.upper_bound({1,1,1});
    int k = it->first.val;
}