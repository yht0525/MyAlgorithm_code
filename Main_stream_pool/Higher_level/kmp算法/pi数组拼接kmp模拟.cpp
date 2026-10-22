#include<iostream>
using namespace std;
//border -> 真公共前后缀 （不能找字符串本身）
//Π -> 最长真公共前后缀的长度

const int N = 1e5+10;

int pi[N];
string give;


//打表pi函数
void get_pi(int len)
{
    pi[1] = 0;
    for(int i=2;i<=len;i++)
    {
        int j = pi[i-1];    //注意：因为j指针不会退 -> 可以不用每一次都赋值j
        while(j && give[i] != give[j+1])
        {
            j = pi[j];
        }
        //防止j为0的时候
        if(give[i] == give[j+1])j++;
        pi[i] = j;
    }
}

int main()
{
    cin>>give;
    string s;
    cin>>s;

    give = " " + s + "&" + give;
    int len = give.length()-1;
    get_pi(len);
    
    for(int i=1;i<=len;i++)
    {
        if(pi[i] == s.length()){
            cout << i - 2 * s.length() << endl; //减去 2*len即可
        }
    }
}