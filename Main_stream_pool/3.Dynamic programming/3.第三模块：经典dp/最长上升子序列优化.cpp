#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int n;
int f[N] , len;
int a[N];

//孩子：要深刻理解二分的奥义！！！

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    
    for(int i=1;i<=n;i++)
    {
        if(i==1 || a[i] > f[len])f[++len] = a[i];
        else
        {
            int le=1,ri=len;
            while(le<ri)            //注意要放在 >=a[i]的最小的元素上
            {
                int mid = (ri+le)/2;
                if(f[mid] >= a[i]){
                    ri = mid;
                }
                else{
                    le = mid+1;
                }
            }
            f[le] = a[i];
        }
    }
    
    cout<<len;
}