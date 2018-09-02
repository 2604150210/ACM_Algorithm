
/**************最少硬币数**************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
int dp[20002];
#define MIN 99999
map<int, int> cn;  // coin and number
int n, m;
int solve(int m) {
  if (dp[m] != 0) return dp[m];
  if (m == 0) return dp[m] = 0;

  for (auto &i : cn) {
    if (m == i.first && i.second) {
      i.second--;
      return dp[m] = 1;
    }
  }
  int min = MIN, cur = MIN;
  for (auto &i : cn) {
    if (i.second > 0 && i.first < m) {
      i.second--;
      cur = solve(m - i.first) + 1;
      i.second++;
    }
    if (min > cur) min = cur;
  }
  return dp[m] = min;
}

int main() {

  cin >> n;
  int k, v;
  for (int i = 0; i < n; i++) {
    cin >> k >> v;
    cn[k] = v;
  }
  cin >> m;
  int x = solve(m);
  if (x <= m)
    cout << x << endl;
  else
    cout << "-1" << endl;
  return 0;
}
/*
3
1 3
2 3
5 3
18
*/
