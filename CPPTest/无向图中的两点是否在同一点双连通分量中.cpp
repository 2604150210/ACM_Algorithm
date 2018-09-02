#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20100;
int n,m,q;
int ecnt,ji,hea,cntt;
struct Edge{
    int next,to;
}edge[MAXN*2];
int F[MAXN],head[MAXN],DFN[MAXN],low[MAXN];
void add(int u,int v){
    edge[ecnt].to = v;
    edge[ecnt].next = head[u];
    head[u] = ecnt++;
}
struct Node{
    int u,v;
}stk[MAXN];
vector<int>v[MAXN];
int sz[MAXN];
void init(){
    ecnt = 1;
    ji = hea = cntt= 0;
    for(int i = 0; i <=n+10; i++){
        F[i] = i;
        head[i] = low[i] = sz[i] = 0;
        DFN[i] = -1;
        v[i].clear();
    }
    memset(edge,0,sizeof(edge));

}
int find(int x){
    if(x == F[x])return x;
    return F[x] = find(F[x]);
}

void tarjan(int x,int f){
    DFN[x] = low[x] = ++ji;
    for(int i = head[x]; i; i = edge[i].next){
        int to = edge[i].to;
        if(to != f){
            Node e;
            e.u = x; e.v = to;
            if(DFN[to] == -1){
                stk[++hea] = e;
                tarjan(to,x);
                low[x] = min(low[x],low[to]);
                if(low[to] >= DFN[x]){//找到割点
                    Node temp;
                    set<int> s;
                    cntt++;//记录点双分量的个数，标记点
                    while(1){
                        temp = stk[hea--];
                        s.insert(temp.u);
                        s.insert(temp.v);
                        v[cntt].push_back(temp.u);
                        v[cntt].push_back(temp.v);
                        if(temp.u == x && temp.v == to)break;
                    }
                    sz[cntt] = s.size();
                }
            }
            else{
                if(DFN[to] < DFN[x])stk[++hea] = e;
                low[x] = min(low[x],DFN[to]);
            }
        }
    }
}
int check(int x,int y){
    int flagx,flagy;
    for(int i = 1; i <= cntt; i++){
        flagx = flagy = 0;
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j] == x){
                if(flagy == 1){
                    if(sz[i] > 2)return 1;
                    else return 0;//当输入的图是两点一线时，为特殊情况，应输出one
                }
                else flagx = 1;
            }
            if(v[i][j] == y){
                if(flagx == 1){
                    if(sz[i] > 2)return 1;
                    else return 0;
                }
                else flagy = 1;
            }
        }
    }
    return 0;
}
int main(){
    int T = 0;
    while(~scanf("%d %d %d",&n,&m,&q)){
        if(n == 0 && m == 0 && q == 0)break;
        init();
        for(int i = 1; i <= m; i++){
            int x,y;
            scanf("%d %d",&x,&y);
            x++;y++;
            add(x,y);add(y,x);
            int fx = find(x);
            int fy = find(y);
            if(fx != fy) F[fx] = fy;
        }
        for(int i = 1; i <= n; i++){
            if(DFN[i] == -1){
                tarjan(i,0);
            }
        }
        printf("Case %d:\n",++T);
        for(int i = 1; i <= q; i++){
            int x,y;
            scanf("%d %d",&x,&y);
            x++;y++;
            int fx = find(x),fy = find(y);
            if(fx != fy){
                printf("zero\n");
                continue;
            }
            if(check(x,y))printf("two or more\n");
            else printf("one\n");
        }
    }
    return 0;
}
/*
http://acm.hdu.edu.cn/showproblem.php?pid=3749

Sample Input
3 1 2
0 1
0 2
1 0
4 4 2
0 1
0 2
1 2
2 3
1 2
1 3
0 0 0


Sample Output
Case 1:
zero
one
Case 2:
two or more
one


*/
