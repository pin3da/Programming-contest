using namespace std;
#include <bits/stdc++.h>

int main() {
  string buff;
  getline(cin, buff);
  int tc = atoi(buff.c_str());

  for (int i = 0; i < tc; ++i) {
    string line;
    getline(cin, line);
    vector<int> ans(26, 0);
    for (int j = 0; j < line.size(); ++j) {
      if (isalpha(line[j])) {
        ans[tolower(line[j]) - 'a']++;
      }
    }
    string cur;
    for (int j = 0; j < ans.size(); ++j) {
      if (ans[j] == 0) {
        cur.push_back(j + 'a');
      }
    }
    
    if (cur.size() == 0) {
      cout << "pangram" << endl;
    } else {
      cout << "missing " << cur << endl;
    }
  }
  return 0;
}
