//任何一个数，他的k倍一定是和数
#include<iostream>
#include<cmath>
using namespace std;
const int N = 1e5+10;

bool st[N];
int p[N];
int cnt,n;

void get_prime()
{

    for(int i=2;i<=n;i++)
    {
        if(!st[i])
        {
            p[++cnt] = i;
            for(int j=i*i;j<=n;j+=i)
            {
                st[j] = true;
            }
        }
    }

}

int main()
{
    cin>>n;     //寻找1~n内的质数，并记录数量
    
    get_prime();

    cout<<cnt;
}