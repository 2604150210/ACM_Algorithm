
/*************素数距离**************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>  //C++³ÌÐòÍ·ÎÄ¼þ   ¶þÑ¡Ò»
using namespace std;
int primer(int n) {
  int ret, i;
  int sq;
  if (n == 1)
    ret = 0;
  else {
    sq = sqrt(n);  //Ê±¼äÓÅ»¯£¬²»ÓÃÃ¿´ÎÑ­»·¶¼ÅÐ¶Ïsqrt£¨n£©
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
  int t;
  cin >> t;
  while (t--) {
    int n, len = 0;
    cin >> n;
    while (1) {
      if (n - len > 1 && primer(n - len)) {
        cout << n - len << " " << len << endl;
        break;
      } else if (primer(n + len)) {
        cout << n + len << " " << len << endl;
        break;
      }
      len++;
        }
    }
    return 0;
}
