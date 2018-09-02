#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 10010;
int dp[MAXN];
char a[MAXN];
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",a);
        int len = strlen(a);
        for(int i = 0; i < len; i++){
            dp[i] = 1;
        }

        for(int i = 1; i < len; i++){
            for(int j = 0; j < i; j ++){
                if(a[j] < a[i]){
                    dp[i] = max(dp[j]+1, dp[i]);
                }
            }
        }
        sort(dp,dp+len);
        printf("%d\n",dp[len-1]);
    }
}
