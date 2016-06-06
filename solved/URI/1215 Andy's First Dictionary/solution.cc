#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  set<string> dic;
  while (cin >> line) {
    stringstream ss(line);
    while (ss >> line) {
      string cur;
      for (auto &i : line) {
        if (!isalpha(i)) {
          if (cur.size())
            dic.insert(cur);
          cur = "";
        } else
          cur += tolower(i);
      }
      if (cur.size())
        dic.insert(cur);
      cur = "";
    }
  }
  for (auto &i : dic)
    cout << i << endl;

  return 0;
}
