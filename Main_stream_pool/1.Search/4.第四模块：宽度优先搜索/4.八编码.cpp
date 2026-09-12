#include<iostream>
#include<queue>
#include<cstring>
#include<unordered_map>
using namespace std;
//data
int pos=0;
const int N = 20;
string ori = "";
string tar = "123804765";
int result;
struct node{
    int num;
    int epi;
    string s;
};
int gox[4] = {-1,0,1,0};
int goy[4] = {0,-1,0,1};
unordered_map<string,int> st;

//交换的函数
string change(int a,int b,string k)
{
    string o = k;
    char temp = o[a];
    o[a] = o[b];
    o[b] = temp;
    return o;
}

void bfs()
{
    queue<node> qu;
    node oro = {pos,0,ori};
    qu.push(oro);
    st[oro.s] = 1;        //走过就不走了（这个是这样吗？）
    
    while(qu.size())
    {
        node topp = qu.front();
        qu.pop();
        
        //一维转二维
        string t = topp.s;
        int n = topp.num;
        int e = topp.epi;
        int y = topp.num/3;
        int x = topp.num%3;

        int nx,ny;
        for(int i=0;i<=3;i++)
        {
            nx = x+gox[i];
            ny = y+goy[i];
            if(nx <= 2 && ny <= 2 && nx >= 0 && ny >= 0)
            {
                int a = nx + 3*ny;
                string ret = change(a,n,t);

                if(!st.count(ret))
                {
                if(ret == tar){
                    result = e+1;
                    return;
                }
                st[ret] = 1;
                qu.push({a,e+1,ret});
                }
                else{
                    continue;
                }
            }
            else{
                continue;
            }
        }
    }  
}


int main()
{
    cin>>ori;
    for(int i=0;i<=8;i++)
    {
        if(ori[i] == '0')pos = i;
    }
    bfs();
    cout<<result;
}