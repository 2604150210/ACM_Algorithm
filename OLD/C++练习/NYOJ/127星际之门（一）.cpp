
/**************星际之门-********************/
#include <iostream>
using namespace std;
// z在一个n接完全图的所有生成树的数量为n的n-2次幂
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int s = 1;
    for (int i = 1; i <= n - 2; i++) {
      s *= n;
      s %= 10003;
    }
    cout << s << endl;
        }
  return 0;
}