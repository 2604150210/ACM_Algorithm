#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    if (n == 0) break;
    std::vector<int> v1;
    std::vector<int> v2;
    int x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      v1.push_back(x);
    }
    for (int i = 0; i < n; i++) {
      cin >> x;
      v2.push_back(x);
    }
    int s1(0), s2(0);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int i = 0; i < n; i++) {
      if (v1[i] > v2[i])
        s1 += 2;
      else if (v1[i] < v2[i])
        s2 += 2;
      else {
        s1++;
        s2++;
      }
    }
    cout << s1 << " vs " << s2 << endl;
  }
  cout << endl << "这次的擂台赛，HDU能赢吗？欲知后事如何，且听下回分解——"
       << endl;
  }
