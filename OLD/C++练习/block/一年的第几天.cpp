//一年的第几天
#include <iostream>
using namespace std;
bool run(int n)  //ÅÐ¶Ï¸ÃÄêÊÇ·ñÎªÈòÄê
{
  int ret;
  if (n % 4 == 0) {
    ret = 1;
    if (n % 100 == 0) {
      ret = 0;
      if (n % 400 == 0) ret = 1;
    }
  } else
    ret = 0;
  return ret;
}
int main() {
  int y, m, d;
  char ch;
  while (cin >> y >> ch >> m >> ch >> d) {
    int s = (0);
    switch (m) {
      case 1:
        s = 0;
        break;
      case 2:
        s = 31;
        break;
      case 3:
        s = 59;
        break;
      case 4:
        s = 90;
        break;
      case 5:
        s = 120;
        break;
      case 6:
        s = 151;
        break;
      case 7:
        s = 181;
        break;
      case 8:
        s = 212;
        break;
      case 9:
        s = 243;
        break;
      case 10:
        s = 273;
        break;
      case 11:
        s = 304;
        break;
      case 12:
        s = 334;
        break;
      default:
        break;
    }
    s = s + d;
    if (run(y) == 1 && m > 2) s++;
    cout << s << endl;
  }
  return 0;
}
