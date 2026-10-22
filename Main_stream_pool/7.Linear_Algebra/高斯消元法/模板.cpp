#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;

const double cmo = 1e-7;        //定义浮点数的小值
//理解主元和自由元
//构建 n*n的矩阵 通过高斯消元将矩阵变成行阶梯型
const int N = 1e2+10;

bool zero(double jud)
{
    if(fabs(jud) < cmo)return true;
    else{
        return false;
    }
}

struct mat{
    double m[N][N];
    int k;
    mat(int n)
    {
        k = n;
        //输入矩阵构造
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n+1;j++)
        {
            cin>>m[i][j];
        }
    }
};

void show(mat a)
{
    int n = a.k;
    for(int i=1;i<=n+1;i++)
    for(int j=1;j<=n;j++)
 {   {
        cout<<a.m[i][j]<<" "; 
    }
    cout<<endl;
}
}


int guass(mat a)
{
    int n = a.k;
    for(int i=1;i<=n;i++)
    {
        //第一步：确定主元
        int aim = i;
        for(int j=i;j<=n;j++)
        {
            if(zero(a.m[j][i]))continue;
            if(fabs(a.m[aim][i]) <fabs(a.m[j][i])){             //寻找主元用绝对值
                aim = j;
            }
        }
        //检查
        if(zero(a.m[aim][i]))continue;
        //交换
        for(int x=1;x<=n+1;x++){
            swap(a.m[aim][x],a.m[i][x]);
        }

        //第二步：消除除了主元所在行的所有元
        //先把主元的这个数设置成1
        for(int x=n+1;x>=i;x--){
            a.m[i][x] /= a.m[i][i];
        }

        for(int j=1;j<=n;j++)
        {
            if(j == i)continue;

            double k = a.m[j][i];
            for(int x=i;x<=n+1;x++)
            {
                a.m[j][x] -= k * a.m[i][x];
            }
        }
    }

    //第三步检查解
    int ret = 1;
    for(int i=1;i<=n;i++)
    {
        if(zero(a.m[i][i]) && !zero(a.m[i][n+1])){
            ret = -1;
            break;
        }

        if(zero(a.m[i][i])){
            ret = 2;
        }
    }

    return ret;
}


int main()
{

}