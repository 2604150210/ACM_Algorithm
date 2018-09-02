
/**************十进制转二进制*****************/
#include <iostream>
using namespace std;

void printbinary(const unsigned int val) {
  for (int i = 32; i >= 0; i--) {
    if (val & (1 << i))
      cout << "1";
    else
      cout << "0";
  }
  cout << endl;
}

int main() {
  int n;
  while (cin >> n) printbinary(n);
  return 0;
}