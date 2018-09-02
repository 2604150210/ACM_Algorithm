
/**************最小生成树prim算法************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <set>
#include <queue>
using namespace std;
#define MIN INT_MAX
#define MAX_Point 120
#define max_Edge 14400
int flag1 = 0;
double sum;
double arr_list[MAX_Point][MAX_Point];
struct Edge {
  int point;
  double lowcost;
  int flag;
};
Edge edge[max_Edge];
double prim(int n) {
  int i, j, k = 1, flag;
  double min, sum2 = 0;
  j = 1;
  for (i = 1; i <= n; i++) {
    if (i != j) {
      edge[i].point = i;
      edge[i].lowcost = arr_list[j][i];
      edge[i].flag = 0;
    }
  }
  edge[j].lowcost = 0;
  edge[j].flag = 1;
  for (i = 2; i <= n; i++) {
    k = 1;
    min = MIN;
    flag = 0;
    for (j = 2; j <= n; j++) {
      if (edge[j].flag == 0 && edge[j].lowcost < min) {
        k = j;
        min = edge[j].lowcost;
        flag = 1;
      }
    }
    if (!flag) return -1;
    sum2 += min;
    edge[k].flag = 1;
    for (j = 2; j <= n; j++) {
      if (edge[j].flag == 0 && arr_list[k][j] < edge[j].lowcost) {
        edge[j].point = k;
        edge[j].lowcost = arr_list[k][j];
      }
    }
  }
  return sum2;
}
int main() {
  double time_data;
  int m;
  int a, b;
  while (cin >> m) {
    if (m == 0) break;
    sum = 0;
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= m; j++) arr_list[i][j] = INT_MAX;
    for (int i = 1; i <= m * (m - 1) / 2; i++) {
      cin >> a >> b >> time_data;
      if (time_data < arr_list[a][b]) {
        arr_list[a][b] = time_data;
        arr_list[b][a] = time_data;
      }
    }
    sum = prim(m);
    cout << sum << endl;
  }
  return 0;
}
