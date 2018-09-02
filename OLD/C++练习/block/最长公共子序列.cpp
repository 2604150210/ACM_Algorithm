#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN=1010;
int dp[MAXN][MAXN];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char s1[1005],s2[1005];
        scanf("%s",s1);
        scanf("%s",s2);
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        int len = min(len1,len2);
        for(int i = 0;i < len2; i++){
            dp[0][i]=0;
        }
        for(int i = 0; i < len1; i++){
            dp[i][0] = 0;
        }
        for(int i = 0; i < len1; i++){
            for(int j = 0; j < len2; j++){
                if(s1[i] == s2[j]){
                    dp[i+1][j+1] = dp[i][j] + 1;
                }
                else{
                    dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        printf("%d\n",dp[len1][len2]);
    }
}
