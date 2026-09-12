//第一个模板： 排序+去重+二分查找离散化
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5+10;

int n;
int tmp[N];
int a[N];
int pos = 0;

// int find1(int x)
// {
//     return lower_bound(tmp + 1,tmp + 1 +pos,x) - (tmp);          //直接用lower_bound或写二分都行
// }

int find2(int x)
{
    int left = 1;int right = pos;
    while(left != right)
    {
        int mid = (left+right)/2;

        if(tmp[mid] < x)
        {
            left = mid+1;
        }
        else{
            right = mid;
        }
    }
    return right;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        tmp[++pos] = a[i];
    }

    //排序+去重
    sort(tmp + 1,tmp + 1 + pos);
    pos = unique(tmp + 1,tmp + 1 +pos) - (tmp+1);

    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" is="<<find2(a[i])<<endl;
    }
}
