#include <iostream>
#include <iomanip>
using namespace std;
void swap(int x, int y) {
  int t;
  t = x;
  x = y;
  y = t;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    if (a * a + b * b == c * c)
      cout << "good" << endl;
    else if (a == b || b == c)
      cout << "perfect" << endl;
    else
      cout << "just a triangle" << endl;
  }
}
