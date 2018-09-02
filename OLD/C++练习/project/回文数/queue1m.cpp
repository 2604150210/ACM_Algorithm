#include <iostream>
#include <cstdlib>
using namespace std;
#include <iomanip>
#include <ctime>
#include "queue1.cpp"

int main() {
  cout << "queue1m.cpp run result:\n";
  cirqueue myqueue;
  int i, x, m, a[3];
  cout << "input number m:";
  cin >> m;
  srand(m);
  cout << "myqueue is :" << endl;
  for (i = 0; i < queuesize;) {
    x = rand() % 1000;
    if (100 <= x && x <= 999) {
      myqueue.enqueue(x);
      i++;
    }
  }
  cout << "length:" << endl;
  cout << myqueue.queuelength() << endl;
  cout << "myqueue:" << endl;
  cout << "is or not is huiwenshu " << endl;
  while (!myqueue.dequeueempty()) {
    x = myqueue.dequeue();
    printf("%4d", x);
    a[0] = x % 10;
    x = x / 10;
    a[1] = x % 10;
    x = x / 10;
    a[2] = x;
    if (a[0] != a[2]) cout << "is not huwen" << endl;
    if (a[0] == a[2]) cout << "is huiwen" << endl;
    cin.get();
    cin.get();
  }
}