#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long dp[2][1<<11];//�ù�������洢������dp״̬��Ŀ
int n,m;
int main(){
    while(~scanf("%d %d",&n,&m) && (n || m)){
        if((n&1) && (m&1))//���n��mͬʱΪ��������ֱ�����0������������
        {
            printf("0\n");
            continue;
        }
        memset(dp,0,sizeof(dp));
        if(m>n)swap(m,n);//ʹ��n>m,��խ��
        int h = 1 <<(m-1);//ֻ�����λΪ1
        dp[0][(1<<m)-1] = 1;
        int cur = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cur^=1;
                memset(dp[cur],0,sizeof(dp[cur]));
                for(int k = 0; k <(1<<m); k++)
                {
                    if(k & h)//[i,j]����ĸ���Ϊ1����[i-1,j]�Ѿ�������
                    {
                        dp[cur][(k^h)<<1]+=dp[cur^1][k];//[i,j]�����
                        if(j && !(k&1))//[i,j-1]δ�����j���ǵ�һ��
                        {
                            //���Ժ�����䣬����[i,j-1]��pi,j]��Ϊ1
                            dp[cur][((k^h)<<1)|3] += dp[cur^1][k];//k^h��Ϊ�˰�k�����λ���0����λ��ʱ���������������λ�������ı�(λ��������666)
                        }
                    }
                    else{
                        if(i)//����ĸ���[i-1,j]δ����䣬��[i,j]ֻ��������䣬������Զ�޷���䵽[i-1,j]
                            dp[cur][((k&(h-1))<<1)|1] += dp[cur^1][k];//k&(h-1)��Ϊ�˰�k�����λ���0����λ��ʱ���������������λ�������ı�(λ��������666)
                    }
                }
            }
        }
        printf("%lld\n",dp[cur][(1<<m)-1]);
    }
    return 0;
}
