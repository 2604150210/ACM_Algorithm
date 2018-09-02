/*************城市平乱**************************/
/*单源最短路径*/
#include <cmath>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000000
int road[2000][2000], s[1050];  // road数组要大小合适才行

int dij[1050];
void Dij(int l, int len) {  // l为源，len为城市数
  memset(s, 0, sizeof(s));
  for (int i = 1; i <= len; i++) {
    dij[i] = road[l][i];
  }
  dij[l] = 0;
  s[l] = 1;
  int v;
  for (int i = 1; i <= len; i++) {
    int path = N;
    for (int j = 1; j <= len; j++) {
      if (!s[j] && dij[j] < path) {
        v = j;
        path = dij[j];
      }
    }

    s[v] = 1;
    for (int k = 1; k <= len; k++) {
      if (!s[k]) dij[k] = min(dij[k], dij[v] + road[v][k]);
    }
  }
}
int main() {
  int t;
  cin >> t;
  int a[102];
  while (t--) {
    int k, len, n, l;
    cin >> k >> len >> n >> l;
    for (int i = 0; i < k; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= len; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j)
          road[i][j] = road[j][i] = 0;
        else
          road[i][j] = road[j][i] = N;
      }
    }
    int x, y, z;
    for (int i = 1; i <= n; i++) {
      cin >> x >> y >> z;
      road[x][y] = road[y][x] =
          min(road[x][y], z);  //将相邻城市的最短的那条路留下
    }
    Dij(l, len);
    for (int i = 0; i < k; i++) {
      a[i] = dij[a[i]];
                }
    sort(a,a+k);
    cout<<a[0]<<endl;
  }
  return 0;
}
