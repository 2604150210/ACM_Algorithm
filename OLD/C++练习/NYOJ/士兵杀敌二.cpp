
/***********士兵杀敌-树状数组*******************/
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn = 100000;
int tree[maxn];
int lowbit(int x) { return (x & -x); }
void add(int x, int value) {
  for (int i = x; i <= maxn; i += lowbit(i)) tree[i] += value;
}
int get(int x) {
  int sum = 0;
  for (int i = x; i; i -= lowbit(i)) sum += tree[i];
  return sum;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int v;
    scanf("%d", &v);
    add(i, v);
  }
  for (int i = 1; i <= m; i++) {
    int a, b;
    char str[10];
    scanf("%s%d%d", &str, &a, &b);
    if (strcmp(str, "ADD") == 0) add(a, b);
    if (strcmp(str, "QUERY") == 0) printf("%d\n", get(b) - get(a - 1));
  }
}