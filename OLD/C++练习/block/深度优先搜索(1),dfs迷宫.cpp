
/*************深度优先搜索（1）dfs迷宫*****************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <set>
using namespace std;
int w, h;
char z[21][21];
int dfs(int i, int j) {
  if (i < 1 || j < 1 || i > h || j > w) return 0;
  if (z[i][j] != '#') {
    z[i][j] = '#';
    return 1 + dfs(i - 1, j) + dfs(i + 1, j) + dfs(i, j - 1) + dfs(i, j + 1);

  } else
    return 0;
}
int main() {
  while (cin >> w >> h) {
    if (w == 0 && h == 0) break;
    for (int i = 1; i <= h; i++)
      for (int j = 1; j <= w; j++) cin >> z[i][j];
    for (int i = 1; i <= h; i++)
      for (int j = 1; j <= w; j++)
        if (z[i][j] == '@') cout << dfs(i, j) << endl;
  }
}