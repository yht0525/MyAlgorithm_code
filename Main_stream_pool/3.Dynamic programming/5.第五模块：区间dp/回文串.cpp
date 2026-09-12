#include<algorithm>
#include<iostream>
using namespace std;

const int N = 1005;
string a = "";
int f[N][N];
int n;

int main()
{
    cin>>a;
    n = a.length();

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            f[i][j] = 0;
        }
    }
    
    for(int len = 2;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j = i+len-1;
            if(a[i-1] == a[j-1]){
                f[i][j] = f[i+1][j-1];
            }
            else{
                f[i][j] = min(f[i+1][j]+1 , f[i][j-1]+1);
            }
        }
    }

    cout<<f[1][n];
    
}