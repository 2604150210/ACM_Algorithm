#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char a[35][35][35];
int vis[35][35][35];
int L, R, C;
struct node{
    int x, y, z, step;
}bg;

int BFS(){
    int next[6][3] = {{0, 0, 1}, {0, 0 ,-1}, {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}};
    memset(vis, 0, sizeof(vis));
    queue<node>que;
    que.push(bg);
    vis[bg.x][bg.y][bg.z] = 1;
    while(!que.empty()){
        node u = que.front(), v;
        que.pop();
        if(a[u.x][u.y][u.z] == 'E')return u.step;
        for(int i = 0; i < 6; i ++ ){
            int x = u.x + next[i][0];
            int y = u.y + next[i][1];
            int z = u.z + next[i][2];
            if(x < L && x >= 0 && y < R && y >= 0 && z < C && z >= 0 && a[x][y][z] != '#' && !vis[x][y][z]){
                v = u;
                v.x = x;
                v.y = y;
                v.z = z;

                v.step = v.step + 1;
                vis[x][y][z] = 1;
                que.push(v);
            }
        }
    }
    return -1;
}
int main(){
    while(cin >> L >> R >> C){
        if(L == 0 && R == 0 && C == 0)break;
        for(int i = 0; i < L; i ++ ){
            for(int j = 0; j < R; j ++ ){
                for(int k = 0; k < C; k ++ ){
                    cin >> a[i][j][k];
                    if(a[i][j][k] == 'S'){
                        bg.x = i;
                        bg.y = j;
                        bg.z = k;
                        bg.step = 0;
                    }
                }
            }
        }

        int s = BFS();
        if(s == -1){
            cout <<"Trapped!" << endl;
        }
        else cout <<"Escaped in " << s << " minute(s)." <<endl;
    }
}
