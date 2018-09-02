#include <iostream>
#include <cstdio>
#include <cmath>
#define PI 3.141592653589793
using namespace std;

int main() {
  double x1, y1, x2, y2, x3, y3;
  while (cin >> x1) {
    cin >> y1 >> x2 >> y2 >> x3 >> y3;

    double a, b, c;
    a = pow((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2), 0.5);
    b = pow((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3), 0.5);
    c = pow((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2), 0.5);

    double p = (a + b + c) / 2;

    double s = pow(p * (p - a) * (p - b) * (p - c), 0.5);
    double r = a * b * c / (4 * s);
    double c1 = PI * 2.0 * r;

    printf("%.2lf\n", c1);
  }
  return 0;
}