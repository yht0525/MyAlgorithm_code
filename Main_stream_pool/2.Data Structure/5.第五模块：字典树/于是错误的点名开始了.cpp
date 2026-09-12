#include<iostream>
#include<cstring>
using namespace std;
int n;
const int N  = 1e6;
int tree[N][26],e[N],p[N];
int idx;
int st[N][26];


void insert(string &a)
{
    int cur = 0;
    p[cur]++;
    for(auto ch:a)
    {
        int t = ch - 'a';
        if(tree[cur][t] == 0)tree[cur][t] = ++idx;
        cur = tree[cur][t];
        p[cur]++;
    }
    e[cur]++;
}

int find(string &a)
{
    int cur = 0;
    for(auto ch:a)
    {
        int t = ch - 'a';
        if(tree[cur][t] == 0)return 0;
        cur = tree[cur][t];
    }
    
    if(e[cur]==1){
    e[cur]++;
    return e[cur]-1;
    }
    else{
        return e[cur];
    }
}


int main()
{
    cin>>n;
    while(n--){
        string a;
        cin>>a;
        insert(a);
    }
    int num;
    cin>>num;
    while(num--)
    {
        string temp;
        cin>>temp;
        int ret = find(temp);
        
        if(ret == 0){
            cout<<"WRONG"<<endl;
        }
        else if(ret == 1){
            cout<<"OK"<<endl;
        }
        else{
            cout<<"REPEAT"<<endl;
        }
    }
}