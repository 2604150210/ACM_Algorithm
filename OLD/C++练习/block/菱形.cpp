
/**************菱形********************/
#include <iostream>
#include <cmath>
using namespace std;
void print(int x0, int y0, int n) {
  int i, j;
  for (i = x0 - n; i <= x0 + n; i++) {

    for (j = y0 - n; j <= y0 + n; j++) {
      if (abs(i - x0) + abs(j - y0) <= n) {
        cout << "*";
      } else
        cout << " ";
    }
    cout << endl;
  }
}

main() {
  print(5, 5, 10);
  return 0;
}