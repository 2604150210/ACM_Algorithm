#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int dp[1<<11][12];
int dis[12][12];
int ans;
int main(){
    while(~scanf("%d",&n)&&n){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                scanf("%d",&dis[i][j]);
            }
        }
        //弗洛伊德算法计算两点间的最短距离
        for(int k = 0; k <= n; k++){
            for(int i = 0; i <= n; i++){
                for(int j = 0; j <= n; j++){
                    if(dis[i][k] + dis[k][j] < dis[i][j]){
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }
        for(int state = 0; state < (1 << n); state ++){//枚举所有状态，用位运算表示
            for(int i = 1; i <= n; i++){
                if(state & (1<<(i-1))){//状态state中已经经过城市i
                    if(state == (1<<(i-1))){////状态State只经过城市i，最优解自然是从0出发到i的dis,这也是DP的边界
                        dp[state][i] = dis[0][i];
                    }
                    else{//如果state经过多个城市
                        dp[state][i] = 0x7fffffff;
                        for(int j = 1; j <= n; j++){
                            if(state&(1<<(j-1)) && j!=i ){
                                dp[state][i] = min(dp[state][i],dp[state^(1<<(i-1))][j]+dis[j][i]);
                            }
                        }
                    }
                }
            }
        }
        ans = dp[(1<<n)-1][1]+dis[1][0];
        for(int i =2; i <= n; i++){
            ans = min(ans,dp[(1<<n)-1][i]+dis[i][0]);//从i点回到0点
        }
        printf("%d\n",ans);
    }
    return 0;
}
