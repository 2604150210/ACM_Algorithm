
/***********网络的可靠性******************/
#include <cmath>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
int n;
using namespace std;
void DO() {
  std::vector<int> v[10001];
  int x, y;
  for (int i = 1; i <= n - 1; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  int du = 0;
  for (int i = 1; i <= n; i++) {
    if (v[i].size() == 1) {
      du++;
    }
  }
  if (du % 2 == 0)
    du /= 2;
  else
    du = du / 2 + 1;
  cout << du << endl;
}
int main() {

  while (cin >> n) {
    DO();
  }
  return 0;
}