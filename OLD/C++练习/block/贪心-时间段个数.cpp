
/**************贪心--时间段的个数***********************/
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
} node[105];

int cmp(inp a, inp b) { return a.y < b.y; }
int main() {
  int n;
  while (cin >> n && n) {
    for (int i = 0; i < n; i++) {
      cin >> node[i].x >> node[i].y;
    }
    sort(node, node + n, cmp);
    int s = 1;
    int j = 0;
    for (int i = 1; i < n; i++) {
      if (node[j].y <= node[i].x) {
        j = i;
        s++;
      }
    }
    cout << s << endl;
  }
  return 0;
}
/*
12
1 3
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
5 10
4 14
2 9
0
*/