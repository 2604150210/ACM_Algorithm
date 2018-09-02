#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int limit = 10000000;
  int n;
  std::vector<int> v;
  v.push_back(1);
  for (int i = 1;; i *= 2) {
    if (i > limit) break;
    for (int j = 1;; j *= 3) {
      if (j * i >= limit) break;
      for (int k = 1;; k *= 5) {
        if (k * j * i >= limit) break;
        v.push_back(i * j * k);
      }
    }
  }
  sort(v.begin(), v.end());
  // cout << v[v.size() - 1] << endl;
  while (cin >> n && n) cout << v[n] << endl;
  return 0;
}