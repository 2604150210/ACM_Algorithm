#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[1005][1005];
char str[1005];
int main(){
    int T;
    cin>>T;
    while(T--){
        scanf("%s",str);
        memset(dp,0,sizeof(dp));
        int len = strlen(str);
        for(int l = 1; l <len; l++){
            for(int i = 0,j = l; i < len&& j< len; i++,j++){
                if(str[i] == str[j]){
                    dp[i][j] = dp[i+1][j-1];
                }else{
                    dp[i][j] = min(dp[i+1][j],dp[i][j-1])+1;
                }
            }
        }
        printf("%d\n",dp[0][len-1] );
    }
}