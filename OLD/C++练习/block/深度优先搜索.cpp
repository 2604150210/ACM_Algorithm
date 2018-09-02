
/***************深度优先搜索**************************/
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int a[10], book[10], n;
void dfs(int step) {
  if (step == n + 1) {
    for (int i = 1; i <= n; i++) cout << a[i];
    cout << endl;
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (book[i] == 0) {
      book[i] = 1;
      a[step] = i;
      dfs(step + 1);
      book[i] = 0;
    }
  }
  return;
}

int main() {
  cin >> n;
  dfs(1);
  return 0;
}
