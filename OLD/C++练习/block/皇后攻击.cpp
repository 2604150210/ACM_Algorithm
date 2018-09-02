
/***************皇后攻击**********************/
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  long long a, b;
  while (cin >> a >> b) {

    if (a < b) swap(a, b);

    long long t1, t2 = 0;
    t1 = a * b * (b - 1) / 2 + b * a * (a - 1) / 2 + (a - b + 1) * b * (b - 1);
    for (int i = 2; i < b; i++) {
      t2 += 2 * i * (i - 1);
    }
    cout << 2 * (t1 + t2) << endl;
  }

  return 0;
}
