#include<bits/stdc++.h>
using namespace std;
vector<string>v;
const int maxn=100000;
char p[maxn];
char s[maxn];
int lenp,lens;
int Next[maxn];
char str[maxn];
void Swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}


//在pStr数组中，[nBegin,nEnd)中是否有数字与下标为nEnd的数字相等
bool IsSwap(char *pStr, int nBegin, int nEnd)
{
    for (int i = nBegin; i < nEnd; i++)
        if (pStr[i] == pStr[nEnd])
            return false;
    return true;
}

// k表示当前选取到第几个数，m表示数组中共有多少数。(k，m对应的是数组中的下标)
void AllRange(char *pStr, int k, int m)
{
    if (k == m)
    {
        int j;
        //cout << pStr << endl;

        string s(strlen(pStr),' ');
        int i;
        for(i = 0; *(pStr+i); i++){
            s[i] = *(pStr+i);
        }
        v.push_back(s);

    }
    else
    {
        for (int i = k; i <= m; i++) // 第i个数分别与它后面的数字交换就能得到新的排列
        {
            if (IsSwap(pStr, k, i))
            {
                Swap(pStr + k, pStr + i);
                AllRange(pStr, k + 1, m);
                Swap(pStr + k, pStr + i);
            }
        }
    }
}


void Permutation(char *pStr)
{
    if (pStr == NULL)
        return;

    AllRange(pStr, 0, (int)strlen(pStr) - 1);
}



void getNext()
{
    int i=0,j=-1;
    memset(Next,0,sizeof(Next));
    Next[0]=-1;
    while(i<lenp)
    {
        if(j==-1||p[i]==p[j])
        {
            i++,j++;
            Next[i]=j;
        }
        else
            j=Next[j];
    }
}
int KMP()
{
    int i=0,j=0;
    int ans=0;
    while(i<lens)
    {
        if(j==-1||s[i]==p[j])
        {
            i++,j++;
        }
        else
            j=Next[j];
        if(j==lenp)
        {
            ans++;
            j=Next[j];
            //若两个不同的匹配没有交集则j=0,
            //若存在交集则j=next[j];
        }
    }
    return ans;
}
int main ()
{
    int T;
    cin>>T;
    while(T--){
        cin>>str>>p;
        v.clear();

        Permutation(str);

        int sum = 0;

        for(string s1: v){

            int i = 0;
            for(auto c:s1){
                s[i++] = c;
            }

            s[i] = 0;
            lens=strlen(s);
            lenp=strlen(p);
            getNext();
            sum += KMP();
            sum %= 1000000007;
        }
        cout << sum<<endl;
    }
    return 0;
}
