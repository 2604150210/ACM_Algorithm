#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/* SPF */
const int MAXN = 1010;
const int WHITE = 0,GREY = 1,BLACK = 2;
int map[MAXN][MAXN];
int DFN[MAXN],low[MAXN],col[MAXN];
int target[MAXN];
int n,ans;
void tarjan(int now, int father, int depth){
    DFN[now] = depth;
    col[now] = GREY;
    int child = 0;
    ans = 0;
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
                target[now] ++;
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
    int T= 0;
    int x,y;
    while(scanf("%d",&x)&&x){
        memset(map,0,sizeof(map));
        memset(col,0,sizeof(col));
        memset(target,0,sizeof(target));
        for(int i = 1; i <= MAXN; i++){
            low[i] = 99999999;//low[i] should initilized INT_MAX;
        }
        n = max(n,x);
        scanf("%d",&y);
        n = max(n,y);
        map[x][y] = map[y][x] = 1;
        while(scanf("%d",&x)&&x){
            n = max(n,x);
            scanf("%d",&y);
            n = max(n,y);
            map[x][y] = map[y][x] = 1;
        }
        printf("Network #%d\n",++T);
        tarjan(1,1,0);
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(target[i]) {
                    cnt++;
            }
        }
        if(cnt == 0){
            printf("  No SPF nodes\n");
        }
        else{
            for(int i = 1; i <= n; i++){
                if(target[i]) {
                        printf("  SPF node %d leaves %d subnets\n",i,target[i]+1);
                }
            }
        }
        cout<<endl;
    }
}
/*

http://poj.org/problem?id=1523

Sample Input

1 2
5 4
3 1
3 2
3 4
3 5
0

1 2
2 3
3 4
4 5
5 1
0

1 2
2 3
3 4
4 6
6 3
2 5
5 1
0

0
Sample Output

Network #1
  SPF node 3 leaves 2 subnets

Network #2
  No SPF nodes

Network #3
  SPF node 2 leaves 2 subnets
  SPF node 3 leaves 2 subnets
*/
