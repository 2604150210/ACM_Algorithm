
/**************一笔画问题**********************/
/*欧拉回路，欧拉通路*/
#include <cmath>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int f[1001];

int getfa(int x) {
  while (f[x] != x) {
    x = f[x];
  }
  return x;
}

void merge(int v, int u) {
  int t1, t2;

  t1 = getfa(v);
  t2 = getfa(u);

  if (t1 != t2) f[t2] = t1;
}

int main() {
  int t;
  cin >> t;
  for (int h = 1; h <= t; h++) {
    memset(f, 0, sizeof(f));
    int p, q;
    cin >> p >> q;
    /*并查集 并查集 并查集 并查集 并查集 并查集 并查集 并查集*/
    for (int i = 1; i <= p; i++) f[i] = i;

    std::vector<int> a[1001];
    int x, y;
    for (int i = 1; i <= q; i++) {
      cin >> x >> y;
      merge(x, y);
      a[x].push_back(y);
      a[y].push_back(x);
    }
    int w = 0;
    for (int i = 1; i <= p; i++) {
      if (f[i] == i) w++;
    }
    if (w > 1) {
      cout << "No" << endl;
      continue;
    }

    int flag = 0, c = 0;
    for (int i = 1; i <= p; i++) {
      int s = a[i].size();
      if (s % 2) {
        c++;
        flag = 1;
      }
    }

    if (flag == 0)
      cout << "Yes" << endl;
    else if (c == 2)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}
