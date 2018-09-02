/*
F题：Decimal integer conversion
时间限制：1000 ms  |  内存限制：65535 KB
描述
XiaoMing likes mathematics, and he is just learning how to convert numbers
between differentbases , but he keeps making errors since he is only 6 years
old. Whenever XiaoMing converts anumber to a new base and writes down the
result, he always writes one of the digits wrong.For example , if he converts
the number 14 into binary (i.e., base 2), the correct result should be"1110",
but he might instead write down "0110" or "1111". XiaoMing never accidentally
adds ordeletes digits, so he might write down a number with a leading digit of "
0" if this is the digit shegets wrong.Given XiaoMing 's output when converting a
number N into base 2 and base 3, please determinethe correct original value of N
(in base 10). (N<=10^10)You can assume N is at most 1 billion, and that there is
a unique solution for N.
输入
The first line of the input contains one integers T, which is the nember of test
cases (1<=T<=8)
Each test case specifies:
* Line 1: The base-2 representation of N , with one digit written incorrectly.
* Line 2: The base-3 representation of N , with one digit written incorrectly.
输出
For each test case generate a single line containing a single integer , the
correct value of N
样例输入
1
1010
212
样例输出
14
*/

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int d2(string s) {
  int ret = 0;
  for (int i = 0; i < s.size(); i++) {
    ret += pow(2, s.size() - i - 1) * (s[i] - '0');
  }
  return ret;
}
int d3(string s) {
  int ret = 0;
  for (int i = 0; i < s.size(); i++) {
    ret += pow(3, s.size() - i - 1) * (s[i] - '0');
  }
  return ret;
}
void DO() {
  string s1, s2;
  cin >> s1 >> s2;
  int flag = 0;
  for (int i = 0; i < s1.size(); i++) {

    if (s1[i] == '0')
      s1[i] = '1';
    else
      s1[i] = '0';  //二进制错一位就是直接取反
    for (int j = 0; j < s2.size(); j++) {
      if (s2[j] == '0') {  //三进制错一位要分类

        s2[j] = '1';
        if (d2(s1) == d3(s2)) {
          cout << d2(s1) << endl;
          flag = 1;
          break;
        }
        s2[j] = '2';
        if (d2(s1) == d3(s2)) {
          cout << d2(s1) << endl;
          flag = 1;
          break;
        }
        s2[j] = '0';
      }

      if (s2[j] == '1') {  //三进制错一位要分类

        s2[j] = '2';
        if (d2(s1) == d3(s2)) {
          cout << d2(s1) << endl;
          flag = 1;
          break;
        }
        s2[j] = '0';
        if (d2(s1) == d3(s2)) {
          cout << d2(s1) << endl;
          flag = 1;
          break;
        }
        s2[j] = '1';
      }

      if (s2[j] == '2') {  //三进制错一位要分类

        s2[j] = '0';
        if (d2(s1) == d3(s2)) {
          cout << d2(s1) << endl;
          flag = 1;
          break;
        }
        s2[j] = '1';
        if (d2(s1) == d3(s2)) {
          cout << d2(s1) << endl;
          flag = 1;
          break;
        }
        s2[j] = '2';
      }
    }
    if (flag == 1) break;
    if (s1[i] == '0')
      s1[i] = '1';
    else
      s1[i] = '0';
  }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        DO();
    }
}
