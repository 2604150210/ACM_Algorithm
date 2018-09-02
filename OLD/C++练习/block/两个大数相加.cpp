
/***********两个大数相加********************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int n = 1; n <= t; n++) {
    string a, b;
    cin >> a >> b;
    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> v3;
    int maxlen = a.size() > b.size() ? a.size() : b.size();
    //将字符串a b转化成整型数组
    for (int i = 0; i < a.size(); i++) v1.push_back(a[a.size() - 1 - i] - '0');
    for (int i = 0; i < b.size(); i++) v2.push_back(b[b.size() - 1 - i] - '0');
    int carry = 0, s;  // carry表示进位
    for (int i = 0; i < maxlen + 1; i++) {
      按位累加
      s = carry;
      s += v1[i] + v2[i];
      v3.push_back(s % 10);
      carry = s / 10;
    }
    int k;
    for (k = maxlen; k >= 0; k--) 找出第一个不为零的数
    if (v3[k] != 0) break;
    cout << "Case " << n << ":" << endl;
    cout << a << " + " << b << " = ";
    while (k >= 0) cout << v3[k--];  //打印输出
    if (n < t) cout << endl;
  }
  return 0;
}
