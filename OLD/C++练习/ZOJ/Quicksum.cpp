#include <iostream>
#include <string>
using namespace std;

int re(char ch) {

  if (ch >= 'A' && ch <= 'Z')
    return ch - 'A' + 1;
  else
    return 0;
}
int main() {
  string s;
  while (getline(cin, s) && s != "#") {
    int sum = 0;
    for (int i = 0; s[i]; i++) {
      sum += (i + 1) * re(s[i]);
    }
    cout << sum << endl;
  }
}