#include<iostream>
#include<deque>
#include<queue>
#include<cstring>
using namespace std;

//data
const int N=35;
int n;
int arr[N][N];
bool st[N][N];
struct node{
    int x;
    int y;
};
int gox[4] = {-1,0,1,0};
int goy[4] = {0,-1,0,1};

void bfs(int x,int y)
{
    queue<node> qu;
    qu.push({x,y});
    st[x][y] = 1;

    while(qu.size())
    {
        node topp = qu.front();
        qu.pop();
        int ox = topp.x,oy = topp.y;

        for(int i=0;i<=3;i++)
        {
            int nox = ox+gox[i],noy = oy+goy[i];
            if(nox>=1 && nox<=n && noy>=1 && noy<=n && !st[nox][noy] && arr[nox][noy] == 0)
            {
                qu.push({nox,noy});
                st[nox][noy] = 1;
            }
        }
    }
}

int main()
{
    memset(st,0,sizeof(st));
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>arr[i][j];
        }
    }

    deque<int> dq;
    dq.push_front(1);
    dq.push_front(0);
    dq.push_front(1);

    int bx,by;
    for(int i=1;i<=n;i++)
    {
        deque<int> dq;
        dq.push_front(1);
        dq.push_front(0);
        dq.push_front(1);
        bx = i;
        for(int j=1;j<=n;j++)
        {
            if(arr[i][j] == dq.front()){
                if(dq.front() == 0)by = j;
                dq.pop_front();
            }
        }
        if(dq.size() == 0)
        {
            break;
        }
    }

    bfs(bx,by);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(!st[i][j]){cout<<arr[i][j]<<" ";}
            else{
                cout<<2<<" ";
            }
        }
        cout<<endl;
    }
}