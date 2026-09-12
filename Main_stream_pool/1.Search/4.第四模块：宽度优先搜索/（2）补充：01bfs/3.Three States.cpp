#include<deque>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;

//data
const int N = 1005;
int n,m;
char arr[N][N];

int gox[4] = {-1,0,1,0};
int goy[4] = {0,-1,0,1};

int dis1[N][N];
int dis2[N][N];
int dis3[N][N];

int ox1,oy1,ox2,oy2,ox3,oy3;

bool reach1,reach2,reach3;

struct node{
    int x;
    int y;
    int epi;
};

queue<node> qu1;
queue<node> qu2;
queue<node> qu3;

//algorithm
void bfs1()
{
    deque<node> du;
    while(qu1.size())
    {
        node tt = qu1.front();
        dis1[tt.x][tt.y] = 0;
        du.push_front(qu1.front());
        qu1.pop();
    }

    while(du.size())
    {
        node topp = du.front();
        du.pop_front();
        int e = topp.epi;
        int ox = topp.x,oy = topp.y;

        for(int i=0;i<=3;i++)
        {
            int nox=ox+gox[i],noy=oy+goy[i];
            if(nox<=n && noy<=m && nox>=1 && noy>=1)
            {
                int ori = 0;
                if(arr[nox][noy] == '#')continue;
                if(arr[nox][noy] == '.')ori = 1;
                else{
                    ori = 0;
                }


                if(dis1[nox][noy] > e+ori){
                    if(ori == 1)
                    {
                        dis1[nox][noy] = e+ori;
                        du.push_back({nox,noy,dis1[nox][noy]});
                    }
                    else{
                        dis1[nox][noy] = e+ori;
                        du.push_front({nox,noy,dis1[nox][noy]});
                    }
                }
            }
        }
    }
}

void bfs2()
{
    deque<node> du;
    while(qu2.size())
    {
        node tt = qu2.front();
        dis2[tt.x][tt.y] = 0;
        du.push_front(qu2.front());
        qu2.pop();
    }

    while(du.size())
    {
        node topp = du.front();
        du.pop_front();
        int e = topp.epi;
        int ox = topp.x,oy = topp.y;

        for(int i=0;i<=3;i++)
        {
            int nox=ox+gox[i],noy=oy+goy[i];
            if(nox<=n && noy<=m && nox>=1 && noy>=1)
            {
                int ori = 0;
                if(arr[nox][noy] == '#')continue;
                if(arr[nox][noy] == '.')ori = 1;
                else{
                    ori = 0;
                }


                if(dis2[nox][noy] > e+ori){
                    if(ori == 1)
                    {
                        dis2[nox][noy] = e+ori;
                        du.push_back({nox,noy,dis2[nox][noy]});
                    }
                    else{
                        dis2[nox][noy] = e+ori;
                        du.push_front({nox,noy,dis2[nox][noy]});
                    }
                }
            }
        }
    }
}

void bfs3()
{
    deque<node> du;
    while(qu3.size())
    {
        node tt = qu3.front();
        dis3[tt.x][tt.y] = 0;
        du.push_front(qu3.front());
        qu3.pop();
    }

    while(du.size())
    {
        node topp = du.front();
        du.pop_front();
        int e = topp.epi;
        int ox = topp.x,oy = topp.y;

        for(int i=0;i<=3;i++)
        {
            int nox=ox+gox[i],noy=oy+goy[i];
            if(nox<=n && noy<=m && nox>=1 && noy>=1)
            {
                int ori = 0;
                if(arr[nox][noy] == '#')continue;
                if(arr[nox][noy] == '.')ori = 1;
                else{
                    ori = 0;
                }


                if(dis3[nox][noy] > e+ori){
                    if(ori == 1)
                    {
                        dis3[nox][noy] = e+ori;
                        du.push_back({nox,noy,dis3[nox][noy]});
                    }
                    else{
                        dis3[nox][noy] = e+ori;
                        du.push_front({nox,noy,dis3[nox][noy]});
                    }
                }
            }
        }
    }
}

int ret[N][N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        cin>>arr[i][j];
        if(arr[i][j] == '1'){
            qu1.push({i,j,0});
        }
        if(arr[i][j] == '2'){
            qu2.push({i,j,0});
        }
        if(arr[i][j] == '3'){
            qu3.push({i,j,0});
        }
    }
    memset(dis1,0x3f,sizeof(dis1));memset(dis2,0x3f,sizeof(dis2));memset(dis3,0x3f,sizeof(dis3));

    bfs1();
    bfs2();
    bfs3();

    int result = 1000001;               //更改：result要尽可能大一点

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(arr[i][j] != '#')
            {
                if(arr[i][j] == '.')
                {
                    ret[i][j] = abs(dis1[i][j] + dis2[i][j] + dis3[i][j] - 2);
                }
                else{
                    ret[i][j] = abs(dis1[i][j] + dis2[i][j] + dis3[i][j]);
                }
                result = min(result,ret[i][j]);
            }
        }
    }

    if(result == 1000001){
        cout<<-1;
    }
    else{
        cout<<result;
    }
}
