#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

const int N = 1e4+10;
string s,t;
int f[N][N];        //表示a的第[1,i]和b的第[1,j]之间的最长公共序列
int lens,lent;

int main()
{
    while(cin>>s>>t)
    {
    
    lens = s.length();
    lent = t.length();
    
    for(int i=1;i<=lens;i++)
    {
        for(int j=1;j<=lent;j++)
        {
            if(s[i-1] == t[j-1]){
                f[i][j] = f[i-1][j-1]+1;
            }
            else{
                f[i][j] = max({f[i-1][j-1],f[i-1][j],f[i][j-1]});
            }
        }
    }
    
    cout<<f[lens][lent]<<endl;
    }
}