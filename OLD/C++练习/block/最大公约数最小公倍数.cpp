
/***************最大公约数和最小公倍数******************/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    int r, max, min;
    min = a * b;
    r = a % b;
    max = b;
    while (r) {
      a = b;
      b = r;
      r = a % b;
      max = b;
    }
    min /= max;
    cout << max << " " << min << endl;
  }
    return 0;
}


