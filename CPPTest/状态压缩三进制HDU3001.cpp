#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 99999999;
int n,m;
int tri[12] = {0,1,3,9,27,81,243,729,2187,6561,19683,59049};//三进制的位权
int dig[59050][11];//dig[state][k_dig]状态state的第k位是多少
int edge[11][11],dp[59050][11];//dp[state][k]为状态state下最后一个点是k的最小距离
int main(){
    for(int i = 0; i < 59050; i++){
        int t = i;
        for(int j = 1;j<=10; j++){
            dig[i][j] = t%3;
            t /= 3;
            if(t == 0)break;
        }
    }
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i  = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                edge[i][j] = MAXN;
            }
        }
        for(int i = 1; i <= n; i++)edge[i][i] = 0;
        int a,b,c;
        for(int i = 1; i <= m; i++){
            scanf("%d %d %d",&a,&b,&c);
            if(c < edge[a][b]){
                edge[a][b] = edge[b][a] = c;
            }
        }
        for(int state = 0; state < tri[n+1]; state++){
            for(int j = 1; j <= n; j++){
                dp[state][j] = MAXN;
            }
        }
        for(int i = 1; i <= n; i++){
            dp[tri[i]][i] = 0;
        }
        int ans = MAXN;
        for(int state = 0; state < tri[n+1]; state++){
            int visit_all = 1;
            for(int i = 1; i <= n; i++){
                if(dig[state][i] == 0)visit_all = 0;
                if(dp[state][i] == MAXN)continue;
                for(int j = 1; j <= n; j++){
                    if(i == j)continue;
                    if(edge[i][j] == MAXN || dig[state][j] >= 2)continue;
                    int newState = state + tri[j];
                    dp[newState][j] = min(dp[newState][j],dp[state][i]+edge[i][j]);
                }
            }
            if(visit_all){
                for(int j = 1; j <= n; j++){
                    ans = min(ans,dp[state][j]);
                }
            }
        }
        if(ans == MAXN){
            puts("-1");
            continue;
        }
        printf("%d\n",ans);
    }
}









