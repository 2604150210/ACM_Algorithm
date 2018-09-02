
/*********畅通工程***********/
#include <cmath>
#include <iostream>
using namespace std;
int f[1000];
int getf(int x) {
  while (x != f[x]) x = f[x];
  return x;
}
void merge(int x, int y) {
  int t1 = getf(x);
  int t2 = getf(y);
  if (t1 != t2) f[t2] = t1;
}
int a[100][100];

int main() {
  int n;
  while (cin >> n) {
    if (n == 0) break;
  }
}