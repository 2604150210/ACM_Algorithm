#include <queue>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 210;
int Map[MAXN][MAXN];
int color[MAXN];
vector<int >v,u;
int vN,uN;///从u寻找匹配
int linked[MAXN];
bool used[MAXN];

bool bfs(int s,int n){///判断是否为二分图
    queue<int>q;
    q.push(s);
    color[s] = 1;
    while(!q.empty()){
        int from = q.front();
        q.pop();
        for(int i = 1; i <= n; i++){
            if(Map[from][i] && color[i] == -1){
                q.push(i);
                color[i] = !color[from];
            }
           else if(Map[from][i] && color[i] == color[from] ){
                return false;
            }
        }
    }
    return true;
}

bool dfs(int u){///求最大匹配
    for(int i = 0; i < vN; i++){
        int vi = v[i];
        if(Map[u][vi] && !used[vi]){
            used[vi] = true;
            if(linked[vi] == -1 || dfs(linked[vi])){
                linked[vi] = u;
                return true;
            }
        }
    }
    return false;
}
int hungary(){///匈牙利算法求二分图的最大匹配
    int res = 0;
    memset(linked,-1,sizeof(linked));
    for(int i = 0; i < uN; i++){
        memset(used,false,sizeof(used));
        if(dfs(u[i])){
            res++;
        }
    }
    return res;
}

int main(){
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        memset(Map,0,sizeof(Map));
        memset(color, -1,sizeof(color));
        for(int i = 1; i <= m; i++){
            int x,y;
            scanf("%d %d",&x,&y);
            Map[x][y] = Map[y][x] = 1;
        }
        bool flag = false;
        for(int i = 1; i <= n; i++){
            if(color[i] == -1 && !bfs(i,n) ){
                flag = true;
                break;
            }
        }
        if(flag){
            printf("No\n");
        }
        else{
            int ans = 0;
            for(int i = 1; i <= n; i++){
                    if(color[i]){
                        v.push_back(i);
                    }else{
                        u.push_back(i);
                    }
            }
            vN = v.size();
            uN = u.size();
            printf("%d\n",hungary());

        }
    }
}
