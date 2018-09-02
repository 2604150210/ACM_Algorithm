#include <iostream>
#include <cmath>
using namespace std;

void DO() {
  int a1, a2, b1, b2;
  cin >> a1 >> a2 >> b1 >> b2;
  int d;
  d = abs(a1 * a2 - b1 * b2);
  cout << d << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    DO();
  }
  return 0;
}