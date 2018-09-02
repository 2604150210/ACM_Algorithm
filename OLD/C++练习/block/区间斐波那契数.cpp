#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char fb[10005][102];
void add(int n);
bool cmp(char *a, char *b);
int main() {
  strcpy(fb[0], "1");
  strcpy(fb[1], "2");
  int k = 1;
  while (strlen(fb[k++]) < 101) {
    add(k);
  }
  char a[102], b[102];
  while (scanf("%s %s", a, b), strcmp(a, "0") != 0 || strcmp(b, "0") != 0) {
    int count = 0;
    for (int i = 0; i <= k; i++) {
      if (cmp(fb[i], a) == 0) continue;
      if (cmp(fb[i], a) == 1 && cmp(b, fb[i]) == 1) count++;
      if (cmp(b, fb[i]) == 0) break;
    }
    cout << count << endl;
  }
  return 0;
}
void add(int n) {
  int len_a = strlen(fb[n - 1]), len_b = strlen(fb[n - 2]);
  int p = len_a - 1, q = len_b - 1;
  int a[102], left = 0;
  for (int i = 0; i < 102; i++) {
    a[i] = left;
    if (p >= 0) a[i] += fb[n - 1][p--] - '0';
    if (q >= 0) a[i] += fb[n - 2][q--] - '0';
    left = a[i] / 10;
    a[i] %= 10;
  }
  int i;
  for (i = 101; i >= 0; i--) {
    if (a[i] != 0) break;
  }
  int k = 0;
  while (i >= 0) {
    fb[n][k++] = a[i--] + '0';
  }
  fb[n][k] = 0;
}
bool cmp(char *a, char *b) {
  int len_a = strlen(a), len_b = strlen(b);
  if (len_a > len_b) return 1;
  if (len_a < len_b) return 0;
  int n = 0;
  while (n < len_a) {
    if (a[n] - '0' > b[n] - '0') return 1;
    if (a[n] - '0' < b[n] - '0') return 0;
    n++;
  }
  return 1;
}
