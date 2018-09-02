#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 100000000, MAX = 13;
const int maxStateNumber = 600;//表示最大合法状态的个数
int M,N,top = 0;//top记录行合法状态的数目，即数组state的长度
int dp[MAX][maxStateNumber];//dp[i][j]表示到第i行时状态为state[j]时的方案数
int state[maxStateNumber],cur[MAX];/*用state数组存储合法的行状态的二进制，即行内没有相邻的1；用cur数组存储田是否允许放牧的二进制状态，1表示不可以放牧，0表示可以放牧*/
inline bool ok(int i){
    return i&(i<<1)?false:true;
}
void init(){
    top = 0;
    int total =( 1 << N);
    for(int i = 0; i < total; i++ ){
        if(ok(i))state[top++] = i;
    }
}
inline bool fit(int state,int line){//判断该状态是否可以用于第line行。
    if(state & cur[line])return false;//state中的二进制数每一位与cur中的二进制每一位按位与，cur为0的位值为0，cur为1的位值与state值相同。如果最后的值为不为0，则表示在不能放牧的格子上放了牛，所以返回false。
    return true;
}
int main(){
    while(~scanf("%d %d",&M,&N)){
        memset(dp,0,sizeof(dp));
        init();
        for(int i = 1; i <= M; i++){
            cur[i] = 0;
            int num;
            for(int j = 1; j <= N; j++){
                scanf("%d",&num);
                if(num == 0)
                    cur[i] += (1 << (N - j));/*将不可放牧点二进制的该位置为1；cur[i]的值的二进制数则表示第i行的每个格子的是否可以放牧的状态，该位为1表示不可以放牧.*/
            }
        }
        for(int i = 0; i < top; i++){
            if(fit(state[i],1)){//state[i]这个状态是否可以填充到第一行
                dp[1][i] = 1;//如果可以填充，则记录dp[1][i]，表示第一行的状态为state[i]时的方案数为1。如果不能填充，依然为默认值0
            }
        }
        for(int i = 2; i <= M; i++){
            for(int j = 0; j < top; j++){
                if(fit(state[j],i) == false)continue;
                for(int k = 0; k < top; k++){
                    if(fit(state[k],i-1) == false)continue;
                    if(state[j] & state[k])continue;//过滤掉上下行之间有相邻的格子的状态，即判断同一位置上的数是不是同时为1
                    dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < top; i++){
            ans  = (ans + dp[M][i]) %MOD;
        }
        printf("%d\n",ans);
    }
}
