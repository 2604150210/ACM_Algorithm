//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 256;
char str[MAXN];
int dp[MAXN][MAXN],pos[MAXN][MAXN];
int l,r;
bool h(char a,char b)
{
    if(a == '(' && b == ')')return true;
    if(a == '[' && b == ']')return true;
    return false;
}
void print(int i, int j)
{
    if(i > j)return ;
    if(i == j)
    {
        if(str[i] == '(' || str[j] == ')')
        {
            printf("()");
        }
        else
        {
            printf("[]");
        }
    }
    else if(pos[i][j] == -1)
    {
        printf("%c",str[i]);
        print(i+1,j-1);
        printf("%c",str[j]);
    }
    else
    {
        print(i,pos[i][j]);
        print(pos[i][j] + 1,j);
    }

}
int main()
{
    while(gets(str))
    {
        int len;
        len = strlen(str);
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < len; i++)
        {
            dp[i][i] = 1;
        }
        int j;
        for(int k = 1; k < len; k++)
        {
            for(int i = 0; i + k < len; i++)
            {
                j = i + k;
                dp[i][j] = 0x7fffffff;
                if(h(str[i],str[j]))
                {
                    dp[i][j] = dp[i+1][j-1];
                    pos[i][j] = -1;
                }
                for(int mid = i; mid <j; mid++)
                {
                    if(dp[i][j] > dp[i][mid] + dp[mid+1][j])
                    {
                        dp[i][j] = dp[i][mid] + dp[mid+1][j];
                        pos[i][j] = mid;
                    }
                }
            }
        }
        print(0,len-1);
        printf("\n");
    }
    return 0;
}
