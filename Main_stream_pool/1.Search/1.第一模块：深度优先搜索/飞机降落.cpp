#include<iostream>
#include<cstring>
using namespace std;
const int N = 15;
int T[N];int D[N];int L[N];

int st[N];
int len=0;
bool jud=false;
int k;

void dfs(int cnt,int n)
{
    if(jud)
    {
        return;
    }
    if(cnt > n)
    {
        jud=true;
        return;
    }

    for(int i=1;i<=n;i++)
    {
        if(st[i] == 1)
        {
            continue;
        }

        if(len <= T[i]+D[i])
        {
            int old=len;
            int start=max(len,T[i]);
            len = start+L[i];
            st[i]=1;

            dfs(cnt+1,n);
            //恢复现场
            len = old;
            st[i] = 0;
        }
    }
}


int main()
{
    cin>>k;
    while(k--)
    {
        memset(st,0,sizeof(st));
        len=0;
        jud=false;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>T[i]>>D[i]>>L[i];
        }
        dfs(1,n);
        if(jud)cout<<"YES"<<endl;
        else{
            cout<<"NO"<<endl;
        }
    }
}