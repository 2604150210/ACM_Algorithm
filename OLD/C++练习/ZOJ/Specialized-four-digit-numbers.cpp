#include <iostream>

using namespace std;

int calc(int k, int b)  //计算和返回k转换成b进制后的个位数字的和
{
  int ret = 0;
  while (k) {
    ret += k % b;
    k /= b;
  }
  return ret;
}

int main() {

  for (int i = 1000; i <= 9999; i++)
    if (calc(i, 10) == calc(i, 12) && calc(i, 10) == calc(i, 16))
      cout << i << endl;

   return 0;
}