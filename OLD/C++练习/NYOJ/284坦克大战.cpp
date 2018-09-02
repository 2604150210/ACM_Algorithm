
/****************坦克大战******************/
/*广搜*/
#include <cmath>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define max 301
int m, n;
struct node {
  int x, y, c;
  friend bool operator<(const node &s1, const node &s2) { return s1.c > s2.c; }
};
node s, e;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
// bool vist[max][max];
char ma[max][max];
int bfs(node s, node e) {
  priority_queue<node> q;
  s.c = 0;
  q.push(s);
  node now, t;

  while (!q.empty()) {
    now = q.top();
    q.pop();
    if (now.x == e.x && now.y == e.y) {
      return now.c;
    }

    for (int i = 0; i < 4; i++) {
      t.x = now.x + dir[i][0];
      t.y = now.y + dir[i][1];
      if (t.x >= m || t.y >= n || t.x < 0 || t.y < 0 || ma[t.x][t.y] == 'S' ||
          ma[t.x][t.y] == 'R')
        continue;
      if (ma[t.x][t.y] == 'B') {
        t.c = now.c + 2;
      } else if (ma[t.x][t.y] == 'E' || ma[t.x][t.y] == 'T') {
        t.c = now.c + 1;
      }
      ma[t.x][t.y] = 'S';
      q.push(t);
    }
  }
  return -1;
}

int main() {
  while (cin >> m >> n) {
    if (m == 0 && n == 0) break;
    for (int i = 0; i < m; i++) {
      scanf("%s", ma[i]);
      for (int j = 0; j < n; j++) {
        if (ma[i][j] == 'Y') {
          s.x = i;
          s.y = j;
        }
        if (ma[i][j] == 'T') {
          e.x = i;
          e.y = j;
        }
      }
    }

    cout << bfs(s, e) << endl;
  }
  return 0;
}
