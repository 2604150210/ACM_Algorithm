#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstring>
#include <set>
using namespace std;
int n,m;
const int MAXN = 201000;//数组要够大....否则会WA
struct Edge{
    int next,to;
} edge[MAXN*2];
int head[MAXN];
int DFN[MAXN],low[MAXN],fa[MAXN];

int ecnt = 1,ji,ans1,ans2,hea;//ans1记录桥的个数，ans2记录点双中边数
struct Node{
    int u,v;
} stk[MAXN];
void add(int u,int v){
    edge[ecnt].to = v;
    edge[ecnt].next = head[u];
    head[u] = ecnt++;
}
void init(){
    memset(edge,0,sizeof(edge));
    ecnt = 1;
    ji = hea = ans1 = ans2 = 0;
    for(int i = 1; i <= n+10; i++){
        fa[i] = head[i] = low[i] = 0;
        DFN[i] = -1;
    }
}
void tarjan(int x){
    DFN[x] = low[x] = ++ji;
    for(int i = head[x]; i; i = edge[i].next){
        int to = edge[i].to;
        if(to != fa[x]){
           Node e;
           e.u = x;
           e.v = to;
           if(DFN[to] == -1){
              stk[++hea] = e;
              fa[to] = x;
              tarjan(to);
              low[x] = min(low[x],low[to]);
              if(low[to] >= DFN[x]){//找到割点
                int num(0);
                Node temp;
                set<int >s;
                while(1){
                    temp = stk[hea--];
                    num++;
                    s.insert(temp.u);
                    s.insert(temp.v);
                    if(temp.u == x && temp.v == to)break;
                }
                if(s.size() < num)ans2+=num;
              }
                if(low[to] > DFN[x])ans1++;//找到桥
           }
           else{
                if(DFN[to] < DFN[x])stk[++hea] = e;
                low[x] = min(low[x],DFN[to]);
           }
        }
    }
}

int main(){
    while(~scanf("%d %d",&n,&m)){
        if(n == 0&&m==0)break;
        init();
        for(int i = 1; i <= m; i++){
            int u,v;
            scanf("%d %d",&u,&v);
            u++,v++;
            add(u,v);
            add(v,u);
        }
        for(int i = 1; i <= n ; i++){
            if(DFN[i] == -1){
                tarjan(i);
            }
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
/*
http://acm.hdu.edu.cn/showproblem.php?pid=3394

Sample Input
8 10
0 1
1 2
2 3
3 0
3 4
4 5
5 6
6 7
7 4
5 7
0 0


Sample Output
1 5

*/
