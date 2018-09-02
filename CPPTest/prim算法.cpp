#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 110;
int maps[MAXN][MAXN];
int vis[MAXN],lowc[MAXN];
int Prim(int n){
    int ret = 0;
    memset(vis,0,sizeof(vis));
    vis[1] = 1;
    lowc[1] = 0;
    for(int i = 2; i <= n; i++){
        lowc[i] = maps[1][i];
    }
    for(int i = 2; i <= n;i++){
        int min = 99999999;
        int p = -1;
        for(int j = 1; j <= n; j++){
            if(vis[j] == 0 && lowc[j] < min){
                min = lowc[j];
                p = j;
            }
        }
        if(min == 99999999)return -1;
        vis[p] = 1;
        ret += min;
        for(int j = 1; j <= n; j++){
            if(vis[j] == 0 && maps[p][j] < lowc[j]){
                lowc[j] = maps[p][j];
            }
        }
    }
    return ret;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                scanf("%d",&maps[i][j]);
            }
        }
        printf("%d\n",Prim(n));
    }
}
