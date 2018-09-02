
/***********回文**************************/
#include <iostream>
#include <string>
using namespace std;
int hw(string s) {
  string s1;
  int len = s.size(), top = 0, mid, next;
  mid = len / 2 - 1;
  for (int i = 0; i <= mid; i++) s1[++top] = s[i];
  if (len % 2 == 0)
    next = mid + 1;
  else
    next = mid + 2;
  for (int i = next; i < len; i++) {
    if (s1[top] != s[i]) break;
    top--;
  }
  if (top == 0)
    return 1;
  else
    return 0;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << hw(s) << endl;
  }
  return 0;
}
