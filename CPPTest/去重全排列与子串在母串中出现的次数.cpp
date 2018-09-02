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


//��pStr�����У�[nBegin,nEnd)���Ƿ����������±�ΪnEnd���������
bool IsSwap(char *pStr, int nBegin, int nEnd)
{
    for (int i = nBegin; i < nEnd; i++)
        if (pStr[i] == pStr[nEnd])
            return false;
    return true;
}

// k��ʾ��ǰѡȡ���ڼ�������m��ʾ�����й��ж�������(k��m��Ӧ���������е��±�)
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
        for (int i = k; i <= m; i++) // ��i�����ֱ�������������ֽ������ܵõ��µ�����
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
            //��������ͬ��ƥ��û�н�����j=0,
            //�����ڽ�����j=next[j];
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
