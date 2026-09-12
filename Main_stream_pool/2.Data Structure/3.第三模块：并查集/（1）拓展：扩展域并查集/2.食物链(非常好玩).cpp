#include<iostream>
using namespace std;

const int N = 5e4 + 10;
int fa[N*3];

int n,k;

int find(int c)
{
    return fa[c] == c?c : fa[c] = find(fa[c]);
}

void un(int a,int b)
{
    int af = find(a);
    int bf = find(b);
    fa[bf] = af;
}

int main()
{
    cin>>n;
    for(int i=1;i<=3*n;i++){
        fa[i] = i;
    }
    cin>>k;
    int ret = 0;
    while(k--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        
        if(b>n || c>n)
        {
            ret++;
            continue;
        }
        if(a == 2 && b == c)
        {
            ret++;
            continue;
        }

        //复杂判断
        if(a == 1)
        {
            if(find(b) == find(c+n) ||            //表示b吃c c吃b -> 都不符合b,c为同类！！！
               find(b) == find(c+2*n))
            {
                ret++;
                continue;
            }
        }
        else{
            int a1 = find(b);
            int b1 = find(c);
            if(a1 == b1 || find(b+n) == find(c))    //b,c不是同类 而且 c不是吃b的！！！
            {
                ret++;
                continue;
            }
        }

        if(a == 1)
        {                               //同类表示：
            un(b,c);                    //b,c为同类
            un(b+n,c+n);                //吃b，吃c的为同类
            un(b+2*n,c+2*n);            //被b，被c吃的是同类
        }
        else{
            un(b,c+n);                  //b和吃c的为同类
            un(c,b+2*n);                //c和被b吃的为同类
            un(b+n,c+2*n);              //吃b的和被c吃的为同类
        }
    }
    
    cout<<ret;  
}