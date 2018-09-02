#include <iostream>
#include <cstdio>
#include <cstlib>
using namespace std;
int f[1010];
int e[1010];
int getf(int c) {
  while (f[c] != c) {
    c = f[c];
  }
  return c;
}
void unio(int a, int b) {
  int t1 = getf(a);
  int t2 = getf(b);
  if (t1 != t2) {
    f[t1] = t2;
  }
}
void en(int a, int b) {
  int t1 = getf(a);
  int t2 = getf(b);
  if (e[a] == 0) {
    e[t1] = t2;
  } else {
    unio(e[a], t2);
  }
  if (e[b] == 0) {
    e[t2] = t1;
  } else {
    unio(e[t2], t1);
  }
}
int main() {
  freopen("data.in", "r", stdin);
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    f[i] = i;
  }
  char r;
  int x, y;
  // cout<<"M:"<<m<<endl;
  for (int i = 1; i <= m; i++) {
    cin >> r >> x >> y;
    if (r == 'F') {
      unio(x, y);
    }
    if (r == 'E') {
      en(x, y);
    }
  }

  int c = 0;
  for (int i = 1; i <= n; i++) {
    if (f[i] == i) c++;
  }
  printf("%d\n", c);
  return 0;
}
