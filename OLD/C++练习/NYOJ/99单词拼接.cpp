
/****************单词拼接*************************/
/*欧拉通路，深搜*/
/*完全看不懂这道题是怎么算的*/
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <string.h>
#include <string>
#include <stack>
using namespace std;
vector<pair<string, bool> > v[26];
int agree_in[26];
int agree_out[26];
int m;
int total;
stack<string> stack_str;
int dfs(string word) {
  char ch;
  ch = word.at(word.length() - 1);
  vector<pair<string, bool> >::iterator i;
  if (v[ch - 'a'].size() == 0) return 0;
  for (i = v[ch - 'a'].begin(); i != v[ch - 'a'].end(); i++) {

    if ((*i).second == 0) {
      (*i).second = 1;
      total++;
      if (total == m || dfs((*i).first) == 1) {
        stack_str.push((*i).first);
        return 1;
      }
      (*i).second = 0;
      total--;
    }
  }
  return 0;
}
int main() {
  int n;
  scanf("%d", &n);
  char str[30];
  int len;
  pair<string, bool> p;
  while (n--) {
    scanf("%d", &m);
    total = 0;
    memset(agree_in, 0, sizeof(agree_in));
    memset(agree_out, 0, sizeof(agree_out));
    int i;
    for (i = 0; i < m; i++) {
      scanf("%s", &str);
      string new_str = str;
      p.first = str;
      p.second = 0;
      v[str[0] - 'a'].push_back(p);
      agree_in[str[0] - 'a']++;
      len = strlen(str);
      agree_out[str[len - 1] - 'a']++;
    }
    bool in_flag = 0, out_flag = 0;
    bool flag = 0;
    int start = -1;
    for (i = 0; i < 26 && flag == 0; i++) {
      switch (agree_in[i] - agree_out[i]) {
        case 1:
          if (in_flag == 1) {
            flag = 1;
            break;
          }
          start = i;
          in_flag = 1;
          break;
        case -1:
          if (out_flag == 1) {
            flag = 1;
            break;
          }
          out_flag = 1;
          break;
        case 0:
          break;
        default:
          flag = 1;
      }
    }
    if (flag == 1) {
      printf("***\n");
      while (!stack_str.empty()) stack_str.pop();
      for (i = 0; i < 26; i++) {
        v[i].clear();
      }
      continue;
    }
    for (i = 0; i < 26; i++) {
      sort(v[i].begin(), v[i].end());
    }
    if (start == -1) {
      for (i = 0; i < 26; i++) {
        if (v[i].size() != 0) {
          start = i;
          break;
        }
      }
    }
    vector<pair<string, bool> >::iterator k;
    for (k = v[start].begin(); k != v[start].end(); k++) {
      (*k).second = 1;
      total++;
      if (dfs((*k).first) == 1) {
        stack_str.push((*k).first);
        break;
      }
      (*k).second = 0;
      total--;
    }
    if (k == v[start].end()) {
      printf("***\n");
      while (!stack_str.empty()) stack_str.pop();
    } else {
      printf("%s", stack_str.top().c_str());
      stack_str.pop();
      while (!stack_str.empty()) {
        printf(".%s", stack_str.top().c_str());
        stack_str.pop();
      }
      printf("\n");
    }
    for (i = 0; i < 26; i++) {
      v[i].clear();
    }
  }
  return 0;
}