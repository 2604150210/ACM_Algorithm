
/*************月老的难题*****************/
/*二分图，匈牙利算法*/
#include <cmath>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
vector<int> g[505];  //记录边
int match[505];
int cnt;
bool flag[505];

bool find(int x) {
  for (int i = 0; i < g[x].size(); i++) {
    int k = g[x][i];
    if (!flag[k]) {
      flag[k] = true;  //标记和x已经匹配过的点，避免重复匹配
      if (!match[k] ||
          find(
              match
                  [k]))  // match[k]不为0，表示k已经和match[k]匹配过了，如果能找到增光路径，即find()为真，则k可以重新匹配，此时匹配数加一
      {
        match[k] = x;
        return true;
      }
    }
  }
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) g[i].clear();
    memset(match, 0, sizeof(match));
    cnt = 0;
    int a, b;
    while (m--) {
      scanf("%d%d", &a, &b);
      g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
      memset(flag, false,
             sizeof(flag));  //清空标记，上一个i匹配过的点，当前i还可以匹配
            if(find(i))
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
