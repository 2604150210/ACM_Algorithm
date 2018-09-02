
/**************时间相加*********************/
#include <iostream>
#include <iomanip>
//#include <cmath>
using namespace std;

int main() {
  while (1) {
    int w = 0, b = 0, c = 0;
    int a[6];
    for (int i = 0; i < 6; i++) cin >> a[i];
    c = a[2] + a[5];
    if (c >= 60) {
      c %= 60;
      b += 1;
    }
    b = a[1] + a[4];
    if (b >= 60) {
      b %= 60;
      w += 1;
    }
    w = a[0] + a[3];
    if (w >= 24) w %= 24;  //<<setw(2)<<setfill('0')
    cout << w << ":" << b << ":" << c << endl;
  }
  return 0;
}

/*
19 45 00 01 30 59
12 00 00 12 31 50
*/
