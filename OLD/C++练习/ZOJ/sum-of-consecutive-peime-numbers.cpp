#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool pr(int n) {
  if (n == 0 || n == 1) return 0;
  if (n == 2) return 1;

  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return 0;
  }

  return 1;
}
int main() {
  std::vector<int> prime;
  for (int i = 2; i < 10000; i++) {
    if (pr(i) == 1) prime.push_back(i);
  }

  int n;
  while (cin >> n && n) {
    int sum(0);
    for (int i = 0; prime[i] <= n; i++) {
      int cnt = 0;
      for (int j = i;; j++) {
        cnt += prime[j];
        if (cnt >= n) break;
      }
      if (cnt == n) sum++;
    }
    cout << sum << endl;
  }
  return 0;
}