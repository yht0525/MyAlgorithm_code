#include<iostream>
#include<deque>
using namespace std;

struct node
{
    int x;
    int y;
    int val;
};


int main()
{
    deque<node> qu;

    //头删
    for(int i=1;i<=5;i++)
    {
        qu.push_front({i,i+1,i*3});
    }

    while(qu.size())
    {
        auto t = qu.front(); qu.pop_front();
        cout<<t.val<<endl;
    }

    //尾删
    for(int i=1;i<=5;i++)
    {
        qu.push_back({i,i,i});
    }

    while(qu.size())
    {
        auto t = qu.back();qu.pop_back();
        cout<<t.val<<endl; 
    }
}
