
/****************单词分离***************************/
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int t;
  cin >> t;  //多组输入
  while (t--) {
    string s;
    cin >> s;                  //以字符串形式读入
    sort(s.begin(), s.end());  //以字典序排序
    for (int i = 0; i < 3; i++) {
      cout << s[i];
      if (i < 2)  //此处输出格式应注意！最后一个字符后面没有空格！
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
