using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

void gen(vector<string> &dict, string &rule, int i, string cur = "") {
  if (i == rule.size()) {
    cout << cur << endl;
    return;
  }
  if (rule[i] == '#') {
    for (int j = 0; j < dict.size(); ++j)
      gen(dict, rule, i + 1, cur + dict[j]);
  } else {
    for (int j = 0; j < 10; ++j)
      gen(dict, rule, i + 1, cur + (char)(j + '0'));
  }
}

void solve(int n) {
  vector<string> dict(n);
  for (auto &i : dict) cin >> i;
  int r; cin >> r;
  string rule;
  while (r--) {
    cin >> rule;
    cout << "--" << endl;
    gen(dict, rule, 0);
  }
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    solve(n);
  }
  return 0;
}
