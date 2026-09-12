#include<iostream>
#include<cstring>
#include<deque>
using namespace std;

//datum
int n,m;
const int N = 505;
char arr[N][N];
int dis[N][N];
int ox,oy,dx,dy;

int gox[4] = {-1,0,1,0};
int goy[4] = {0,-1,0,1};

struct node{
    int x;
    int y;
    int epi;
};

void bfs()
{
    deque<node> du;
    du.push_front({ox,oy,0});

    while(du.size())
    {
        node topp = du.front();
        du.pop_front();
        int oox = topp.x,ooy = topp.y;
        int e = topp.epi;
        
        for(int i=0;i<=3;i++)
        {
            int nox = oox+gox[i],noy = ooy+goy[i];
            if(nox<n && nox>=0 && noy<m && noy>=0)
            {
                int ori = 0;
                if(arr[oox][ooy] == arr[nox][noy]){ori = 0;}
                else{ori = 1;}
                
                if(dis[nox][noy] > e+ori)                       //不用st判断 -> 改用dis的比较判断！！！
                {
                    dis[nox][noy] = e+ori;
                    if(ori==1)
                    {
                        du.push_back({nox,noy,dis[nox][noy]});
                    }
                    else{
                        du.push_front({nox,noy,dis[nox][noy]});
                    }
                }
            }
        }
    }
}

int main()
{
    while(cin>>n>>m , (n!=0 || m!=0))
    {
        memset(dis,0x3f,sizeof(dis));
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin>>arr[i][j];

        cin>>ox>>oy>>dx>>dy;

        bfs();

        cout<<dis[dx][dy]<<endl;
    }
}