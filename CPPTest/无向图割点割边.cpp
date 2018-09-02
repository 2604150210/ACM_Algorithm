#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 110;
const int WHITE = 0,GREY = 1,BLACK = 2;
int map[MAXN][MAXN];
int DFN[MAXN],low[MAXN],col[MAXN];
bool vis[MAXN];
int target[MAXN];
int n,ans;
void tarjan(int now, int father, int depth){
    DFN[now] = depth;
    col[now] = GREY;
    int child = 0;
    for(int i = 1; i <= n; i++){
        if(map[now][i] == 0)continue;

        if( i != father && col[i] == GREY){// i is u'grandfather
            low[now] = min(low[now],DFN[i]);
        }
        if(col[i] == WHITE ){// i is u'child
            tarjan(i,now,depth+1);
            child++;
            low[now] = min(low[i],low[now]);
            if((now == 1 && child > 1) || (now != 1 && low[i] >= DFN[now])){//is ge dian
                target[now] = 1;
                //ans++;  //注意：需要记录该割点增加几个联通分量的操作需要在这里ans++
            }
            /*
            if(low[i] > DEN[now]){
                target[now][i] = 1;//now->i is ge edge;
            }
            */
        }
    }
    col[now] = BLACK;
}
int main(){
    while(scanf("%d",&n)&&n){
        int u,v;
        memset(map,0,sizeof(map));
        memset(col,0,sizeof(col));
        memset(target,0,sizeof(target));
        for(int i = 1; i <= n; i++){
            low[i] = 99999999;//low[i] should initilized INT_MAX;
        }
        while(scanf("%d",&u) && u){
            while(getchar() != '\n'){
                scanf("%d",&v);
                map[u][v] = map[v][u] = 1;
            }
        }
        tarjan(1,1,0);
        ans = 0;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(target[i] == 1) {
                    cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}
/*

http://poj.org/problem?id=1144


Sample Input

5
5 1 2 3 4
0
6
2 1 3
5 4 6 2
0
0
Sample Output

1
2

*/
