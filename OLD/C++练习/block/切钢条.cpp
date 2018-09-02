
/****************切钢条*************************/
#include <iostream>
#include <cstring>
using namespace std;
int p[100] = {0,   1,   5,   8,   9,   10,  17,  17,  20,  24,  30,  40,
              43,  46,  49,  50,  55,  60,  63,  65,  70,  72,  77,  79,
              81,  84,  89,  91,  92,  94,  96,  97,  98,  99,  100, 110,
              112, 120, 126, 129, 130, 136, 150, 155, 157, 159, 160, 166,
              168, 169, 170, 172, 175, 179, 180, 183, 185, 186, 190, 199};
int n;
int dp[100];
int f(int n) {
  if (n == 0) return dp[0] = 0;
  if (dp[n] != 0) return dp[n];
  int max = 0;
  for (int i = 1; i <= n; i++) {
    int t = p[i] + f(n - i);
    if (t > max) max = t;
  }
  return dp[n] = max;
}
int main() {

  while (cin >> n) cout << f(n) << endl;
  return 0;
}