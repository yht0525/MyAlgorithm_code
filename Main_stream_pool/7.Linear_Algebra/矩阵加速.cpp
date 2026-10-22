#include<cstring>
#include<iostream>
using namespace std;

typedef long long LL;
const int N = 10;
const int MOD = 1e9+7;

struct mat{
    LL m[N][N];
    LL k;            //规定矩阵的规模，默认为正方矩阵
    
    mat(int t,int tag)
    {
        memset(m,0,sizeof(m));
        k = t;
        
        if(tag == 1){
            for(int i=1;i<=k;i++)
            {
                m[1][i] = 1;
            }
         }
        else if(tag == 0){
            //建立递推乘法矩阵
            m[1][1] = m[3][1] = m[2][3] = m[1][2] = 1;
        }
    }

    //乘法要返回在一个新的矩阵里面
    mat operator*(const mat& b)const
    {
        mat C(3,-1);
        int n = k;
        
        for(int i = 1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int x=1;x<=n;x++)
                {
                  C.m[i][j] = (C.m[i][j] + m[i][x] * b.m[x][j])%MOD;  
                }
            }
        }

        return C;
    }
    
}A(3,1),RET(3,0);

void qpow(LL x)
{
    if(x <= 0){
        A.m[1][1] = A.m[1][3+x];
        return;
    }
    while(x)
    {
        if(x & 1){
            A = A * RET;
        }
        RET = RET * RET;
        x = x>>1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;cin>>t;
    while(t--)
    {
        LL n;
        cin>>n;
        qpow(n-3);
        printf("%lld\n",A.m[1][1]);

        //注意初始化问题
        A = mat(3,1);   
        RET = mat(3,0);
    }
}