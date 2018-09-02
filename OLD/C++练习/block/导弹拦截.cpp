#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100;
int dp[MAXN];
int a[MAXN];
int main(){
        int n;
        while(scanf("%d",&n)!=EOF){

        for(int i = 0; i < n; i ++){
            scanf("%d",&a[i]);
            dp[i] = 1;
        }
        for(int i = n-2; i >= 0; i--){
            for(int j = n-1; j > i; j--){
                if(a[j] < a[i]){
                    dp[i] = max(dp[i], dp[j] +1);
                }
            }
        }
        sort(dp,dp+n);
        printf("%d\n",dp[n-1]);
        }
}
