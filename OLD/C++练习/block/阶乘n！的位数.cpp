
/********阶乘的位数**************************8/
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
/*对于每个n，输出n！的（十进制）位数
所谓n！的十进制位数，就是lg n！+1，
根据数学公式，有n！=1*2*3*...*n,
所以lg n!=lg2+...+lgn.*/
int main() {
  int n;

  double sum;
  while (cin >> n) {
    sum = 0.0;
    for (int i = 2; i <= n; i++) sum += log10(i);
    cout<<(int )sum+1<<endl;
  }
  return 0;
}
