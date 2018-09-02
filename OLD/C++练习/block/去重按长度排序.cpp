
/***********去重按长度排序*************************/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  //此头文件不可忘记添加
using namespace std;
inline void output_words(vector<string> &words) {
  for (auto m : words) cout << m << " ";
  cout << endl;
}
bool isShorter(const string &s1, const string &s2) {
  return (s1.size() < s2.size());
}
void elimDups(vector<string> &sv) {
  output_words(sv);
  sort(sv.begin(), sv.end());  //先按照字典序排序
  output_words(sv);
  auto end_unique = unique(sv.begin(), sv.end());
  output_words(sv);
  sv.erase(end_unique, sv.end());  //再去重
  output_words(sv);
  stable_sort(sv.begin(), sv.end(), isShorter);  //最后按长度排序
  output_words(sv);
}

int main(int argc, char *argv[]) {
  vector<string> words;
  string word;
  while (cin >> word) words.push_back(word);
  elimDups(words);
    return 0;

}


