
/***********大数阶乘*************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int main() {
  int n, c, k;
  const int maxn = 50000;
  int f[maxn + 1];
  // vector<int> f(maxn + 1, 0);
  while (cin >> n) {
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
      c = 0;
      for (int j = 0; j <= maxn; j++) {
        int s = f[j] * i + c;
        f[j] = s % 10;
        c = s / 10;
      }
    }
    for (k = maxn; k >= 0; k--)
      if (f[k] != 0) break;
    for (int i = k; i >= 0; i--) cout << f[i];
    cout << endl;
  }

  return 0;
}
