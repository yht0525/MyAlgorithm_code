#include<iostream>
using namespace std;
//data
const int N = 1e5+10;
int n;
int t;
int fa[N]; 
int d[N];

void init()
{
    for(int i=1;i<=n;i++)
    {
        fa[i] = i;
        d[i] = 0;
    }
}

int find(int x)
{
    if(fa[x] == x)return x;

    int t = find(fa[x]);
    d[x] += d[fa[x]];

    return fa[x] = t;
}

void un(int b,int a,int w)
{
    int af = find(a),bf = find(b);

    if(af != bf)
    {
        fa[bf] = af;
        d[bf] = d[a] + w - d[b];
    }
}

int main()
{
    cin>>n>>t;
    int cot = 0;
    init();                 //不要忘记初始化！
    
    while(t--)
    {
        int ju,a,b;
        cin>>ju>>a>>b;
        
        if(a>n || b>n)
        {
            cot++;
            continue;
        }
        if(ju==2 && a==b)
        {
            cot++;
            continue;
        }

        //complicated jud
        if(find(a) == find(b))
        {
        if(ju==1 && (((d[a] - d[b]) % 3 + 3) % 3 == 2 || ((d[a] - d[b]) % 3 + 3) % 3 == 1))         //((a - b)%3 + 3) % 3 ==> 可以有效防止越界！！！
        {
            cot++;
            continue;
        }
        if(ju==2 && (((d[a] - d[b]) % 3 + 3) % 3 == 2 || ((d[a] - d[b]) % 3 + 3) % 3 == 0))
        {
            cot++;
            continue;
        }
        }

        if(ju == 1)
        {
            un(a,b,0);
        }
        else{
            un(a,b,1);
        } 
    }
    
    cout<<cot;
}