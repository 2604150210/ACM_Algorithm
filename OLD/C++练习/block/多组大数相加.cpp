
/******************多组大数相加********************************/
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
  for (int x = 1; x <= t; x++) {
    int maxlen = 0;
    std::vector<int> a;
    std::vector<string> v;
    int v1[200][200];
    string s1;
    int num;
    for (num = 0; num < 200; num++) {
      cin >> s1;
      if (s1 == "0") break;
      int len = s1.size();
      if (maxlen < len) maxlen = len;
      v.push_back(s1);
      for (int i = 0; i < len; i++) {
        int e = s1[len - 1 - i] - '0';
        // cout << e << " ";
        v1[num][i] = e;
      }
    }
    /* for (int i = 0; i < num; i++)  //将字符转换成数字
     {
       for (int j = 0; j < v[i].size(); j++) {
         cout << "yunxingdaoci" << endl;
         v1[i][j] = v[i][v[i].size() - j - 1] - '0';
       }
     }*/

    int carry = 0, s, digit;
    for (int j = 0; j < maxlen + 2; j++) {

      s = carry;
      for (int i = 0; i < num; i++) {

        s += v1[i][j];
      }
      digit = s % 10;

      carry = s / 10;

      a.push_back(digit);
      // cout << "yunxing" << endl;
    }
    int k;

    for (k = maxlen + 2; k >= 0; k--)
      if (a[k] != 0) break;
    while (k >= 0) cout << a[k--];
    cout << endl;
    if (x < t) cout << endl;
  }
  return 0;
}
/*
1
99999278961257987
126792340765189
998954329065419876
432906541
23
0
*/