#include <iostream>
#include <cmath>
//#include <vector>
using namespace std;
bool prime(int n) {
  int ret, i;
  int sq;
  if (n == 1)
    ret = 0;
  else {
    sq = sqrt(n);
    for (i = 2; i <= sq; i++)
      if (n % i == 0) {
        ret = 0;
        break;
      }
    if (i > sq) ret = 1;
  }
  return ret;
}
int main() {
  int a, d, n;
  while (cin >> a >> d >> n) {
    if (a == 0 && d == 0 && n == 0) break;

    // std::vector<int> v;
    int c = 0, i = 0;
    while (c < n) {
      if (prime(a + (i++) * d)) c++;
    }
    i--;
    cout << a + i* d << endl;
  }
}