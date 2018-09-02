#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
int n,m;
const int MAXN = 1004;
struct Edge{
    int next,to;
} edge[MAXN*5];
int head[MAXN];
int DFN[MAXN],low[MAXN],belong[MAXN],du[MAXN];

int ecnt = 1,ji,ans,cntt;//cntt表示边双连通分量的个数
stack<int>s;
void add(int u,int v){
    edge[ecnt].to = v;
    edge[ecnt].next = head[u];
    head[u] = ecnt++;
}
void tarjan(int x,int fa){
    low[x] = DFN[x] = ++ji;
    s.push(x);
    for(int i = head[x]; i; i = edge[i].next){
        int to = edge[i].to;
        if(to != fa){
            if(DFN[to] == -1){
                tarjan(to,x);
                low[x] = min(low[to],low[x]);
            }else{
                low[x] = min(low[x],DFN[to]);
            }
        }
    }
    if(low[x] > DFN[fa]){
        cntt++;
        while(1){
            int temp = s.top();
            s.pop();
            belong[temp] = cntt;
            if(temp == x)break;
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++){
        DFN[i] = -1;
    }
    for(int i = 1; i <= m; i++){
        int u,v;
        scanf("%d %d",&u,&v);
        add(u,v);
        add(v,u);
    }
    tarjan(1,0);
    for(int i = 1; i <= n; i++){
        for(int j = head[i]; j; j = edge[j].next){
            int to = edge[j].to;
            if(belong[to] != belong[i]){
                du[belong[to]]++;
                du[belong[i]]++;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        du[i] /=2;
    }
    for(int i = 1; i <= n; i++){
        if(du[i] == 1){
            ans++;
        }
    }
    ans = (ans+1)/2;
    cout<<ans<<endl;
}
/*

poj 3352

Sample Input

Sample Input 1
10 12
1 2
1 3
1 4
2 5
2 6
5 6
3 7
3 8
7 8
4 9
4 10
9 10

Sample Input 2
3 3
1 2
2 3
1 3
Sample Output

Output for Sample Input 1
2

Output for Sample Input 2
0
*/
