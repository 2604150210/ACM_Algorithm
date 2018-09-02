#include <iostream>
#include <cstdio>
#define PI 3.1415926
using namespace std;
int main() {
  double r;
  while (cin >> r) {
    double v = PI * r * r * r * 4.0 / 3.0;
    // cout << v << endl;
    printf("%.0f\n", v);
  }
  return 0;
}
