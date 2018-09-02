
//**********括号配对**********************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {

  string str;
  while (cin >> str) {
    stack<char> sk;
    int i = 0;
    while (str[i]) {
      if (sk.empty())
        sk.push(str[i]);
      else {
        if (sk.top() == '[' && str[i] == ']' ||
            sk.top() == '{' && str[i] == '}' ||
            sk.top() == '(' && str[i] == ')')
          sk.pop();
        else
          sk.push(str[i]);
      }
      i++;
    }
    if (sk.empty())
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}