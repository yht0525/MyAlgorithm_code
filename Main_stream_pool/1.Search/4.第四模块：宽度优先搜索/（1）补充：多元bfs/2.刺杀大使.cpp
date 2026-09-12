#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

//二分 加 bfs

//data
int gox[4] = {-1,0,1,0};
int goy[4] = {0,-1,0,1};

const int N = 1e3+10;
int arr[N][N];
int n,m;

struct node{
    int x;
    int y;
};

int st[N][N];

bool bfs(int lim)
{
    memset(st,0,sizeof(st));
    bool jud = false;
    queue<node> qu;
    qu.push({1,1});
    st[1][1] = 1;
    int cot = 1;

    
    while(qu.size())
    {
        node topp = qu.front();
        qu.pop();
        int ox = topp.x,oy = topp.y;
        for(int i=0;i<=3;i++)
        {
            int nox = ox+gox[i],noy = oy+goy[i];
            if(nox<=n && nox>=1 && noy<=m && noy>=1 && !st[nox][noy] && arr[nox][noy] <= lim)
            {
                cot = max(cot,nox);
                if(cot == n){
                    return true;
                }
                qu.push({nox,noy});
                st[nox][noy] = 1;
            }
        }
    }
    
    return jud;
}

int main()
{
    int mi = 1001,ma = 0;
    
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>arr[i][j];
            if(i!=1 && i!=n)
            {
                mi = min(mi,arr[i][j]);
                ma = max(ma,arr[i][j]);
            }
        }
    }

    int right = ma;
    int left = mi;

    while(right != left)
    {
        int mid = (right+left)/2;
        if(bfs(mid)){
            right = mid;
        }
        else{
            left = mid+1;
        }
    }

    cout<<left;
}