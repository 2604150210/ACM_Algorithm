#include <cmath>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[1000000];
int s[1000000];
int main() {
  int n, m;
  cin >> n >> m;

  a[0] = 0;

  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }

  s[0] = 0;
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
  }
  int x, y;
  while (m--) {
    scanf("%d%d", &x, &y);
    int e;
    e = s[y] - s[x] + a[x];
    printf("%d\n", e);
  }
}