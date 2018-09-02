#include <iostream>
#include <vector>
using namespace std;
int a[26];
int main() {
  string s;
  std::vector<string> v;
  for (int i = 0; i < 4; i++) {
    getline(cin, s);
    v.push_back(s);
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      if (v[i][j] >= 'A' && v[i][j] <= 'Z') a[v[i][j] - 'A']++;
    }
  }
  int t = 0;
  for (int i = 0; i < 26; i++) {
    if (t < a[i]) t = a[i];
  }
  for (int j = 1; j <= t; j++) {
    for (int i = 0; i < 26; i++) {
      if (10 - a[i] < j)
        cout << "*";
      else
        cout << " ";
      if (i != 25) cout << " ";
    }
    cout << endl;
  }
  char ch = 'A';
  for (int i = 0; i < 26; i++) {
    cout << ch++;
    if (i != 25) cout << " ";
  }
  cout << endl;
  return 0;
}