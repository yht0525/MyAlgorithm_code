#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

const int N = 2e3+10;
string a,b;
int lena,lenb;

int f[N][N];                    //f[][]意义是从1号位置 到a串的i和b串的j号位置 的最小更改操作次数

int main()
{
    cin>>a>>b;        
    lena = a.length();
    lenb = b.length();

    //memset(f,0x3f,sizeof(f));
    f[0][0] = 0;
    for(int i=1;i<=lena;i++)f[i][0] = i;
    for(int j=1;j<=lenb;j++)f[0][j] = j;
    
    for(int i=1;i<=lena;i++)
    {
        for(int j=1;j<=lenb;j++)
        {
            if(a[i-1] == b[j-1])
            {
                f[i][j] = f[i-1][j-1];                                          //判断最后一位是否相等
            }
            else{
                f[i][j] = min({f[i-1][j-1]+1,f[i-1][j]+1,f[i][j-1]+1});         //细心想好三种情况！！！
            }
        }
    }
    
    cout<<f[lena][lenb];   
}