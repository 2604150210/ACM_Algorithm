
/******************贪心-Javabean**********************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;
struct inp {
  int x, y;
  double c;
} node[1005];
int cmp(inp a, inp b) { return a.c > b.c; }
int main() {
  int m, n;
  while (cin >> m >> n) {
    if (m == -1 || n == -1) break;
    for (int i = 0; i < n; i++) {
      cin >> node[i].x >> node[i].y;
      node[i].c = 1.0 * node[i].x / node[i].y;
    }
    sort(node, node + n, cmp);
    double j = 0.0;
    for (int i = 0; i < n; i++) {
      if (m >= node[i].y) {

        j += node[i].x;
        m -= node[i].y;

      } else {
        j += m * node[i].c;
        break;
      }
    }
    cout << fixed << setprecision(3) << j << endl;
  }
  return 0;
}
/*
5 3
7 2
4 3
5 2
-1 -1
*/