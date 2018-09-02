#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
  string name;
  int p1, time1, p2, time2, p3, time3, p4, time4;
  int ps;  //每个队ac题的数量和
  int pe;  //总得罚时
} Item;

Item a[50];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].name >> a[i].p1 >> a[i].time1 >> a[i].p2 >> a[i].time2 >>
        a[i].p3 >> a[i].time3 >> a[i].p4 >> a[i].time4;
    a[i].ps = 0;
    a[i].pe = 0;
  }

  for (int i = 0; i < n; i++) {
    if (a[i].time1) {
      a[i].ps++;
      a[i].pe += (a[i].p1 - 1) * 20 + a[i].time1;
    }
    if (a[i].time2) {
      a[i].ps++;
      a[i].pe += (a[i].p2 - 1) * 20 + a[i].time2;
    }
    if (a[i].time3) {
      a[i].ps++;
      a[i].pe += (a[i].p3 - 1) * 20 + a[i].time3;
    }
    if (a[i].time4) {
      a[i].ps++;
      a[i].pe += (a[i].p4 - 1) * 20 + a[i].time4;
    }
  }
  // Item t;t.ps=0;t.pe=0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i].ps <= a[j].ps) {
        swap(a[i], a[j]);
        if (a[i].ps == a[j].ps) {
          if (a[i].pe > a[j].pe) swap(a[i], a[j]);
        }
      }
    }
  }

  cout << a[0].name << " " << a[0].ps << " " << a[0].pe << endl;
}