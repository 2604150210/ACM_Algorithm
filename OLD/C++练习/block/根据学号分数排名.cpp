
/**********根据学号分数排名******************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
int main() {

  string j;
  while (cin >> j) {
    map<string, int> m;
    pair<string, int> x;
    while (cin >> x.first >> x.second) {
      if (x.first == "0" && x.second == 0) break;
      m.insert(x);
    }
    auto it = m.find(j);
    int a = it->second;
    int r = 1;
    for (auto t : m) {
      if (t.second > a) r++;
    }
    cout << r << endl;
  }

  return 0;
}
