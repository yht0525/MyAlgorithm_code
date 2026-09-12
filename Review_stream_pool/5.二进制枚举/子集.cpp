#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int N = 1e4;
int n;
int a[N];
vector<vector<int>> ret;

int main()
{
    cin>>n;
    
    for(int i=0;i<(1 << n);i++)
    {
        vector<int> tem;
        for(int j=0;j<n;j++)            //表示第j位置的结果！！！
        {
            if( ((i>>j) & 1) == 1 )
            {
                tem.push_back(a[j]);
            }
        }
        ret.push_back(tem);
    }
    
}