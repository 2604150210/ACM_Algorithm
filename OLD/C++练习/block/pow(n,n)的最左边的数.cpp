
/*****************n的n次方最左边的数*************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
/*求正整数pow（n，n）的最左边的数d，
d=pow（10，lg（pow（n，n））-lg（pow（n，n）））

*/
int main() {
  int t;
  cin >> t;
  double x = 0.0;
  int n;
  while (t--) {
    cin >> n;
    x = n * log10((double)n);
    x -= (long long)x;
    x = (int)pow(10, x);
                cout<<x<<endl;
  }
  return 0;
}
