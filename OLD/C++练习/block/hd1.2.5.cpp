#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    char op;
    int a, b;
    cin >> op >> a >> b;
    if (op == '+')
      cout << a + b << endl;
    else if (op == '-')
      cout << a - b << endl;
    else if (op == '*')
      cout << a* b << endl;
    else
      a % b ? (cout << fixed << setprecision(2) << 1.0 * a / b << endl)
            : (cout << a / b << endl);
  }
}
