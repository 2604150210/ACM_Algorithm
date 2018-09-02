#include <iostream>
#include <vector>
using namespace std;

int main() {
  double x;
  while (cin >> x && x) {
    std::vector<double> v;
    v.push_back(0.0);
    int i;
    for (i = 2;; i++) {
      if (v.back() >= x) break;
      double tmp = v.back() + 1.0 / i;
      v.push_back(tmp);
    }
    cout << i - 2 << " card(s)" << endl;
  }
  return 0;
}