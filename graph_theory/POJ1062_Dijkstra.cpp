//
// Created by jal on 18-7-27.
//

#include <iostream>
#include <cstring>
using namespace std;
const int N = 101;
const int INF = 99999999;
int price[N][N];
int dis[N];
bool vis[N];
int level[N];
int n, m;
int Dijkstra(){
    for(int i = 1; i <= n; i++){
        dis[i] = price[0][i];
    }
    for(int i = 1; i <= n; i++){
        int min_d = INF, k = 0;
        for(int j = 1; j <= n; j++){
            if(!vis[j] && dis[j] < min_d){
                min_d = dis[ k = j];
            }
        }
        vis[k] = true;
        for(int j = 1; j <= n; j++){
            if(!vis[j] && dis[j] > dis[k] + price[k][j]){
                dis[j] = dis[k] + price[k][j];
            }
        }
    }
    return dis[1];
}
int main(){
    cin >> m >> n;
    memset(dis, INF, sizeof(dis));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            price[i][j] = INF;
        }
    }
    for(int i = 1; i <= n; i++){
        int p,l,x;
        cin >> p >> l >> x;
        price[0][i] = p;
        level[i] = l;
        for(int j = 1; j <= x; j++){
            int t,v;
            cin >> t >> v;
            price[t][i] = v;
        }
    }
    int minimum_distance = INF;
    for(int i = 1; i <= n; i++){
        int min_level = level[i];
        for(int j = 1; j <= n; j++){
            if(level[j] < min_level || level[j] - min_level > m){
                vis[j] = true;
            }
            else{
                vis[j] = false;
            }
        }
        int now_min_distance = Dijkstra();
        minimum_distance = min(minimum_distance, now_min_distance);
    }
    cout << minimum_distance << endl;

}
