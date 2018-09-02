//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int INF = 0x7fffffff;
int n,m;
int dp[8200][15][15];//状态dp[k][i][j]表示点的状态为k，k为二进制表示法，二进制中哪一位是1，则表示该点在状态中。倒数第二个点为i，倒数第一个点为j时的最优解
long long sum[8200][15][15],v[21];
int mp[21][21];
int main(){
    int T;
    cin>>T;
    while(T--){
        memset(mp,0,sizeof(mp));
        scanf("%d %d",&n,&m);
        for(int i = 1; i <= n; i++){
            scanf("%d",&v[i]);
        }
        for(int i = 1; i <= m; i++){
            int x,y;
            scanf("%d %d",&x,&y);
            mp[x][y] = mp[y][x] = 1;
        }
        if(n == 1){
            printf("%d 1\n",v[1]);
            continue;
        }
        memset(dp,-122,sizeof(dp));
        memset(sum,0,sizeof(sum));
        dp[0][0][0] = 0;
        sum[0][0][0] = 1;
        v[0] = 0;
        for(int i = 1; i <= n; i++){
            mp[i][0] = 1;
            mp[0][i] = 1;
        }

        for(int k = 0; k <((1<<n)-1); k++){
            for(int i = 0; i <= n; i++){
                for(int j = 0; j <= n; j++){
                    if(dp[k][i][j] != -1){
                        for(int q = 1; q <= n; q++){
                            if(q != i && q != j && mp[j][q]){
                                int u = (1 << (q-1));//表示下一点取q的二进制状态
                                if((k & u) > 0)continue;//说明q点已经在Hamilton回路中，则跳过该点
                                int value = v[q] * v[j] + v[q];
                                if(mp[i][q]) value += v[q] * v[j] * v[i];//存在三角形，则j->q的路径花费为三部分组成
                                if(dp[k|u][j][q] < dp[k][i][j] + value ){
                                    //更新该路径的最大值
                                    dp[k|u][j][q] = dp[k][i][j] + value;
                                    sum[k|u][j][q] = sum[k][i][j];
                                }
                                else if(dp[k|u][j][q] == dp[k][i][j] + value ){
                                    //更新该路径的个数
                                    sum[k|u][j][q] += sum[k][i][j];
                                }
                            }
                        }
                    }
                }
            }
        }
        int best = -INF;
        long long best_cnt = 0;
        int k = (1 << n) - 1;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(dp[k][i][j] > best){
                    best = dp[k][i][j];
                    best_cnt = sum[k][i][j];
                }
                else if(dp[k][i][j] == best){
                    best_cnt += sum[k][i][j];
                }
            }
        }
        if(best_cnt == (long long ) 0){
            best = 0;
        }
        printf("%d %lld\n",best,best_cnt/2);
    }
    return 0;
}
