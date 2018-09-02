#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  // feropen("data.in", "r", stdin);

  double x;
  while (cin >> x && x != -1) {
    std::vector<double> v;
    v.push_back(x);
    while (cin >> x && x) {
      v.push_back(x);
    }
    int s(0);
    for (int i = 0; i < v.size(); i++) {
      for (int j = 0; j < v.size(); j++) {
        if (v[i] / v[j] == 2) {
          s++;
          // cout << v[i] << "\/" << v[j] << endl;
        }
      }
    }

    cout << s << endl;
  }

  return 0;
}