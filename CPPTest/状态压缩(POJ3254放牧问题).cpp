#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 100000000, MAX = 13;
const int maxStateNumber = 600;//��ʾ���Ϸ�״̬�ĸ���
int M,N,top = 0;//top��¼�кϷ�״̬����Ŀ��������state�ĳ���
int dp[MAX][maxStateNumber];//dp[i][j]��ʾ����i��ʱ״̬Ϊstate[j]ʱ�ķ�����
int state[maxStateNumber],cur[MAX];/*��state����洢�Ϸ�����״̬�Ķ����ƣ�������û�����ڵ�1����cur����洢���Ƿ���������Ķ�����״̬��1��ʾ�����Է�����0��ʾ���Է���*/
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
inline bool fit(int state,int line){//�жϸ�״̬�Ƿ�������ڵ�line�С�
    if(state & cur[line])return false;//state�еĶ�������ÿһλ��cur�еĶ�����ÿһλ��λ�룬curΪ0��λֵΪ0��curΪ1��λֵ��stateֵ��ͬ���������ֵΪ��Ϊ0�����ʾ�ڲ��ܷ����ĸ����Ϸ���ţ�����Է���false��
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
                    cur[i] += (1 << (N - j));/*�����ɷ���������Ƶĸ�λ��Ϊ1��cur[i]��ֵ�Ķ����������ʾ��i�е�ÿ�����ӵ��Ƿ���Է�����״̬����λΪ1��ʾ�����Է���.*/
            }
        }
        for(int i = 0; i < top; i++){
            if(fit(state[i],1)){//state[i]���״̬�Ƿ������䵽��һ��
                dp[1][i] = 1;//���������䣬���¼dp[1][i]����ʾ��һ�е�״̬Ϊstate[i]ʱ�ķ�����Ϊ1�����������䣬��ȻΪĬ��ֵ0
            }
        }
        for(int i = 2; i <= M; i++){
            for(int j = 0; j < top; j++){
                if(fit(state[j],i) == false)continue;
                for(int k = 0; k < top; k++){
                    if(fit(state[k],i-1) == false)continue;
                    if(state[j] & state[k])continue;//���˵�������֮�������ڵĸ��ӵ�״̬�����ж�ͬһλ���ϵ����ǲ���ͬʱΪ1
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
