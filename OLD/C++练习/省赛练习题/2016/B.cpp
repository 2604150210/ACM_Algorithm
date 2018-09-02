#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DO() {
  int n, k;
  cin >> n;
  std::vector<int> v;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  cin >> k;
  sort(v.begin(), v.end());
  auto w = unique(v.begin(), v.end());
  v.erase(w, v.end());
  if (k > v.size())
    cout << v[0] << endl;
  else
    cout << v[v.size() - k] << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    DO();
  }
  return 0;
}