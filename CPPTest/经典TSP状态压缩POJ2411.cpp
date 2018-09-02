//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int INF = 0x7fffffff;
int n,m;
int dp[8200][15][15];//״̬dp[k][i][j]��ʾ���״̬Ϊk��kΪ�����Ʊ�ʾ��������������һλ��1�����ʾ�õ���״̬�С������ڶ�����Ϊi��������һ����Ϊjʱ�����Ž�
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
                                int u = (1 << (q-1));//��ʾ��һ��ȡq�Ķ�����״̬
                                if((k & u) > 0)continue;//˵��q���Ѿ���Hamilton��·�У��������õ�
                                int value = v[q] * v[j] + v[q];
                                if(mp[i][q]) value += v[q] * v[j] * v[i];//���������Σ���j->q��·������Ϊ���������
                                if(dp[k|u][j][q] < dp[k][i][j] + value ){
                                    //���¸�·�������ֵ
                                    dp[k|u][j][q] = dp[k][i][j] + value;
                                    sum[k|u][j][q] = sum[k][i][j];
                                }
                                else if(dp[k|u][j][q] == dp[k][i][j] + value ){
                                    //���¸�·���ĸ���
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
