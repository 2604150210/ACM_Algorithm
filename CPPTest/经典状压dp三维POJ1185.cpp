#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N,M;
const int maxStateNumber = 100,MAXN = 20,MAXM = 110;
char mp[MAXM][MAXN],num[maxStateNumber],top;
int state[maxStateNumber],cur[MAXM];
int dp[MAXM][maxStateNumber][maxStateNumber];
inline bool ok(int x){
    if(x & (x<<1) )return 0;
    if(x & (x<<2) )return 0;
    return 1;
}
void init(){
    top = 0;
    int total = (1 << N);
    for(int i = 0; i < total; i++){
        if(ok(i))state[++top] = i;
    }
}
//����x�Ķ���������1�ĸ���
inline int cnt(int x){
    int ret = 0;
    while(x){
        ret++;
        x&=(x-1);
    }
    return ret;
}
inline bool fit(int state,int x){
    if(state&cur[x])return false;
    return true;
}
int main(){
    while(~scanf("%d %d",&M,&N)){
        if(N==0&&M==0)break;
        init();
        for(int i = 1; i <= M; i++){
            scanf("%s",mp[i]+1);
        }
        for(int i =1; i <= M; i++){
            cur[i] = 0;
            for(int j = 1; j <= N; j++){
                if(mp[i][j] == 'H')cur[i] +=(1 << (N-j));
            }
        }
        memset(dp,-1,sizeof(dp));
        //��ʼ����һ�е�״̬
        for(int i = 1; i <= top; i++){
            num[i] = cnt(state[i]);//state�������������е�״̬���ҳ���״̬��1�ĸ�������Ϊ���Է��õĴ��ڵĸ���
            if(fit(state[i],1)){//���state[i]��״̬���Է����һ�У����ϸ��dp��ֵ������dp��Ϊ��ʼֵ-1
                for(int j = 1; j<=top; j++)
                dp[1][j][i] = num[i];
            }
        }
        for(int i = 2; i <= M; i++){
            for(int j = 1; j <= top; j++){
                if(!fit(state[j],i))continue;
                for(int k = 1; k <= top; k++){
                    if(!fit(state[k],i-1))continue;
                    if(state[j]&state[k])continue;
                    for(int t = 1; t <= top; t++){
                        if(!fit(state[t],i-2))continue;
                        if(state[j]&state[t])continue;
                        if(state[k]&state[t])continue;
                        //if(dp[i-1][t][k] == -1)continue;
                        dp[i][k][j] = max(dp[i][k][j],dp[i-1][t][k] + num[j]);
                    }
                }
            }
        }
        int maxvalue = -1;
        for(int i= 0; i <= top; i++){
            for(int j = 0; j<= top; j++){
                maxvalue = max(maxvalue,dp[M][i][j]);
            }
        }
        printf("%d\n",maxvalue);
    }
}













