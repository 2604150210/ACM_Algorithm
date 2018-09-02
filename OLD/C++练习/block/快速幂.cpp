#include <iostream>
using namespace std;
long long powmod(long long a, long long n) {
  if (n == 1) return a%1000;
  if (n == 0) return 1%1000;
  long long t = powmod(a, n / 2);
  t = t * t % 1000;
  if (n % 2 == 1) t = t * a % 1000;
  return t ;
}
int main() {
  long long a, b;
  while (cin >> a >> b) {
        if(a == 0 && b == 0)break;
    long long s = powmod(a, b);
    cout<<s<<endl;
  }
}
