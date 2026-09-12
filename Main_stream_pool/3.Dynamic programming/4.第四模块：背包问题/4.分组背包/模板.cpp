#include<iostream>
#include<vector>
using namespace std;

const int N = 1e4+10;

struct node{
    int w;
    int v;
};

vector<node> v[N];
int m,n;
int f[N][N];
int sum;

int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        int a1,b1,c1;
        cin>>a1>>b1>>c1;
        v[c1].push_back({a1,b1});
        sum = max(sum,c1);
    }

    for(int i=1;i<=sum;i++)
    {
        for(int j=1;j<=m;j++)
        {
            f[i][j] = f[i-1][j];
            for(auto t:v[i])
            {
                if(j>=t.w)f[i][j] = max(f[i][j] , f[i-1][j-t.w]+t.v);               
            }
        }
    }

    cout<<f[sum][m];
}