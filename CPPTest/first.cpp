<<<<<<< HEAD
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 100005
#define LL unsigned long long
#define inf 0x7ffffff
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;
LL f[N];
char s[N];
int n;
struct node
{
    int l,r;
    LL suml,sumr;//��¼�����Һʹ��ҵ����hashֵ
}tree[4*N];
void pushup(int o)
{
    tree[o].suml = tree[2*o].suml + tree[2*o+1].suml;
    tree[o].sumr = tree[2*o].sumr + tree[2*o+1].sumr;
}
void build(int o,int l,int r)
{
    tree[o].l = l;
    tree[o].r = r;
    if(l == r)  {
        tree[o].suml = f[l-1]*(s[l-1] - 'a');
        tree[o].sumr = f[n-l]*(s[l-1] - 'a');
        return ;
    }
    int m = (l+r)/2;
    build(2*o,l,m);
    build(2*o+1,m+1,r);
    pushup(o);
}
void update(int o,int pos,int num)
{
    if(tree[o].l == tree[o].r){
        tree[o].suml = f[ tree[o].l - 1 ]*num;
        tree[o].sumr = f[ n-tree[o].l ]*num;
        return ;
    }
    int m = (tree[o].l+tree[o].r)/2;
    if(pos <= m)    update(2*o,pos,num);
    else update(2*o+1,pos,num);
    pushup(o);
}
LL suml,sumr;
void query(int o,int x,int y)
{
    if(x <= tree[o].l && tree[o].r <= y)
    {
        suml += tree[o].suml;
        sumr += tree[o].sumr;
        return;
    }
    int m = (tree[o].l+tree[o].r)/2;
    if(m >= x)  query(2*o,x,y);
    if(y > m)   query(2*o+1,x,y);
}
int main()
{
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    int i;
    f[0] = 1;
    for(i = 1; i < N; i++)
        f[i] = f[i-1]*27;
    while(scanf("%s",s) != EOF)
    {

        n = strlen(s);
        build(1,1,n);
        int q;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%s",s);
            if(s[0] == 'p')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                suml = sumr = 0;
                query(1,x,y);
                int k1 = x-1;
                int k2 = n-y;
                if(k1 > k2) sumr *= f[k1-k2];//�����Լ��ٸ�������һ��
                else suml *= f[k2-k1];
                if(suml == sumr)    printf("Yes\n");
                else printf("No\n");
            }
            else{
                int x;
                scanf("%d%s",&x,s);
                update(1,x,s[0]-'a');
=======
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
>>>>>>> 75a19ca89a5d6d01fb5e40bd95fd80c9ac17c923
            }
        }
        printf("%lld\n",dp[cur][(1<<m)-1]);
    }
    return 0;
}
