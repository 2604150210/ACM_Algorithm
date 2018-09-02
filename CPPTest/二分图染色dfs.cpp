#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 210;
vector<int>graph[MAXN*MAXN];
bool color[MAXN],vis[MAXN];
bool dfs(int u){
    vis[u] = true;
    int len = graph[u].size();
    for(int i = 0; i < len; i++){
        int v = graph[u][i];
        if(vis[v] == false){
            color[v] = color[u]^1;
            if(dfs(v) == false)return false;
        }
        else{
            if(color[v] == color[u]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        memset(graph,0,sizeof(graph));
        memset(vis,false,sizeof(vis));
        memset(color,0,sizeof(color));

        for(int i = 0; i < m; i++){
            int x,y;
            scanf("%d %d",&x, &y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        int flag = true;
        for(int i = 1; i <= n; i++){
            if(vis[i] == false)
            if(dfs(i) == false){
                flag = false;
                break;
            }
        }
        if(flag == false){
            printf("No\n");
        }
        else{
            int ans = 0;
            for(int i= 1; i <= n; i++){
                ans+=color[i];
            }
            int ans1 = n - ans;
            printf("%d\n",max(ans,ans1));
        }
    }
}
