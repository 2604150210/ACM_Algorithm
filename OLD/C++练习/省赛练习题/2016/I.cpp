#include <iostream>
#include <map>
#include <cstring>
using namespace std;
char a[1005], b[1005], c[1005];
string sa, sb;
map<char, int> m;
int main() {
  m['\0'] = 0;
  for (int i = 0; i < 26; i++) {
    m[i + 'a'] = i;
  }
  int t;
  cin >> t;
  while (t--) {
    cin >> sa >> sb;
    bool flag1 = 0, flag2 = 0;  // flag为0表示没有小数点
    memset(a, 'a', sizeof(a));
    memset(b, 'a', sizeof(b));
    memset(c, 'a', sizeof(c));
    for (int i = 0; sa[i]; i++) {
      if (sa[i] == '.') {
        flag1 = 1;
        break;
      }
    }
    for (int i = 0; sb[i]; i++) {
      if (sb[i] == '.') {
        flag2 = 1;
        break;
      }
    }

    // a和b都是整数
    if (flag1 == 0 && flag2 == 0) {

      for (int i = 0; i < sa.size(); i++) {
        a[sa.size() - 1 - i] = sa[i];
      }
      for (int i = 0; i < sb.size(); i++) {
        b[sb.size() - 1 - i] = sb[i];
      }

      int sc = 0;
      for (int i = 0; i <= 1000; i++) {
        c[i] = m[a[i]] + m[b[i]] + sc;
        sc = c[i] / 26;
        c[i] %= 26;
        c[i] += 'a';
      }

      int k;
      for (k = 1000; k >= 1; k--) {
        if (c[k] != 'a') break;
      }
      for (int i = k; i >= 0; i--) cout << c[i];
      cout << endl;
    }

    // b是整数 a是小数
    if (flag1 == 1 && flag2 == 0) {
      swap(a, b);
      flag1 = 0;
      flag2 = 1;
    }

    // a是整数，b是小数
    if (flag1 == 0 && flag2 == 1) {
      int d;  //标记小数点的位置
      char z[1000], x[1000];
      memset(z, 'a', sizeof(z));
      memset(x, 'a', sizeof(x));
      for (int i = 0; i < sa.size(); i++) {
        a[sa.size() - i - 1] = sa[i];
      }
      for (int i = 0; sb[i]; i++) {
        if (sb[i] == '.') d = i;
      }

      for (int i = 0; i < d; i++) {  //小数点左边是整数
        z[d - 1 - i] = sb[i];
      }
      cout << "***" << endl;
      int j = 0;
      for (int i = d + 1; i <= 1000; i++) {  //小数点右边是小数
        x[j++] = sb[i];
      }

      //整数部分与整数部分相加
      int sc = 0;
      for (int i = 0; i < 1000; i++) {
        c[i] = m[a[i]] + m[z[i]] + sc;
        sc = c[i] / 26;
        c[i] %= 26;
        c[i] += 'a';
      }

      int k;
      for (int k = 1000; k >= 1; k--) {
        if (c[k] != 'a') break;
      }
      for (int i = k; i >= 0; i++) {
        cout << c[i];
      }
      cout << '.';
      int r;
      for (int r = 1000; r >= 0; r--) {
        if (x[r] != 'a') break;
                }
   		for(int i=0;i<=r;i++)cout<<x[i];
   		cout<<endl;
   }
}
return 0;
}