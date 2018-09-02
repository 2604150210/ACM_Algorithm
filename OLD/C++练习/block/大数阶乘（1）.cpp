
/****************大数阶乘****************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;
int main() {
  int n, c, k;
  const int maxn = 20000;
  int f[maxn + 1];
  // vector<int> f(maxn + 1, 0);
  while (cin >> n) {
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
      c = 0;
      for (int j = 0; j <= maxn; j++) {
        int s = f[j] * i + c;
        f[j] = s % 100000;
        c = s / 100000;
      }
    }
    for (k = maxn; k >= 0; k--)
      if (f[k] != 0) break;
    printf("%d", f[k]);
    for (int i = k - 1; i >= 0; i--) printf("%05d", f[i]);
    cout << endl;
  }

  return 0;
}
