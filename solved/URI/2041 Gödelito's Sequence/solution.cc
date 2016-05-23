#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int count(string s, int id, char c) {
  int i = id;
  for (int id; i < s.size() && s[i] == c; ++i);
  return i - id;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string s = "3";
  vector<string> ans;
  ans.emplace_back(s);
  for (int i = 0; i < 41; ++i) {
    int j = 0;
    string next;
    while (j < s.size()) {
      char c = s[j];
      int f = count(s, j, c);
      j += f;
      string tmp = to_string(f);
      for (auto &i : tmp)
        next.push_back(i);
      next.push_back(c);
    }
    s = next;
    ans.emplace_back(s);
  }
  int n;
  while (cin >> n) {
    cout << ans[n - 1] << endl;
  }
  return 0;
}
