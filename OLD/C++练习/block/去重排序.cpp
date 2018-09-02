/****************去重排序************************/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void elimDups(vector<int>& iv) {
  sort(iv.begin(), iv.end());                      //排序
  auto end_unique = unique(iv.begin(), iv.end());  //重复的元素靠后排
  iv.erase(end_unique, iv.end());  //删除后面的重复的元素
}
int main() {
  vector<int> ivec;
  int val;
  while (cin >> val) ivec.push_back(val);
  elimDups(ivec);
  for (auto m : ivec) cout << m << " ";
    cout<<endl;
    return 0;

}


