
/************字符型数字转换成整型数字******************/
#include <iostream>
using namespace std;
int get(char ch) { return ch - 48; }
int main() {
  char a;
  cin >> a;
  cout << get(a) << endl;
}