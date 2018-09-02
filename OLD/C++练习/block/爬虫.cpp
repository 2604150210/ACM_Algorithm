
/*************爬虫******************/
#include <iostream>
using namespace std;

int main() {
  int n, u, d;
  while (cin >> n >> u >> d) {

    if (n == 0) break;
    int s(0), m(0);
    while (1) {  // cout<<"yunxingdaoci"<<endl;
      s += u;
      m++;
      if (s >= n) break;
      s -= d;
      m++;
    }
    cout << m << endl;
  }
}
