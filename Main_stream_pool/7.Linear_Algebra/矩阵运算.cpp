#include<cstring>
#include<iostream>
using namespace std;

typedef long long LL;
const int MOD = 1e9+7;
const int N = 1e2+10;

//============================矩阵快速幂===================================

int n;
LL k;

struct mat{
    LL m[N][N];

    mat()
    {
        memset(m,0,sizeof(m));
    }

    mat operator*(const mat& b) const
    {
        mat C;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int z=1;z<=n;z++)
                    C.m[i][j] = (C.m[i][j] + m[i][z]*b.m[z][j])%MOD;
        return C;
    }
}A,RET;


void qpow(LL k)
{
    for(int i=1;i<=n;i++)RET.m[i][i] = 1;
    
    while(k)
    {
        if(k & 1){
            RET = RET * A;
        }
        A = A*A;
        k = k>>1;
    }
}


int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>A.m[i][j];
        }

    qpow(k);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<RET.m[i][j]<<" ";
        }
        cout<<endl;
    }
}