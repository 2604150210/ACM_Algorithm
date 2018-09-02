#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 310;
bool Map[MAXN][MAXN];
int link[MAXN];
bool used[MAXN];
int p,n;
bool dfs(int u){
    for(int i = 1; i <= p; i++){
        if(Map[u][i] && used[i] == false ){
            used[i] = true;
            if(link[i] == -1 || dfs(link[i])){
                link[i] = u;
                return true;
            }
        }
    }
    return false;
}
int hungary(){
    memset(link,-1,sizeof(link));
    int ret = 0;
    for(int i = 1; i <= n; i++){
        memset(used,0,sizeof(used));
        if(dfs(i))ret++;
    }
    return ret;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        scanf("%d %d",&p,&n);
        memset(Map,0,sizeof(Map));
        for(int i = 1; i <= p; i++){
            int m;
            scanf("%d",&m);
            for(int j = 1; j <= m; j++){
                int x;
                scanf("%d",&x);
                Map[x][i] = 1;
            }
        }
        if(p == hungary()){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

}
