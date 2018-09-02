#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef struct arrow {
  int a, b, c;
} Item;
bool compare(Item x, Item y) { return x.a < x.b; }
void DO() {
  int n;
  cin >> n;
  Item x;
  std::vector<Item> v;
  for (int i = 0; i < n; i++) {
    cin >> x.a >> x.b >> x.c;
    v.push_back(x);
  }
  int t;
  cin >> t;
  int s = 0;
  for (int i = 0; i < n; i++) {
    s += v[i].c;
  }
  if (s > t)
    cout << "Oh,my god!" << endl;

  else {
    int d = t - s;
    sort(v.begin(), v.end(), compare);
    int i;
    for (i = 0; i < n; i++) {
      if (d <= 0) break;
      d = d + v[i].c - v[i].a;
    }
    i;
    cout << i << endl;
  }
}
int main() {
  freopen("stdin.txt", "r", stdin);

  freopen("stdout.txt", "w", stdout);
  int T;
  cin >> T;
  while (T--) {
    DO();
  }
  return 0;
}