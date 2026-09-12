#include<iostream>
using namespace std;
int n;
string path="";

void dfs(int pos)
{
    if(pos > n)
    {
        cout<<path<<endl;
        return;
    }

    path+="N";
    dfs(pos+1);
    path.pop_back();
    
    path+="Y";
    dfs(pos+1);
    path.pop_back();
}

int main()
{
    cin>>n;
    dfs(1);
}