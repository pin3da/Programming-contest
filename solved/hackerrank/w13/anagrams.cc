using namespace std;
#include <bits/stdc++.h>

void solve() {
  string line;
  cin >> line;
  map<string, int> ans;
  for (int i = 0; i < line.size(); ++i) {
    for (int j = 1; j + i - 1 < line.size(); ++j) {
      string tmp = line.substr(i, j);
      sort(tmp.begin(), tmp.end());
      ans[tmp]++;
    }
  }

  long long res = 0;
  for (map<string, int>::iterator it = ans.begin(); it != ans.end(); ++it)
    res += (it->second * (it->second - 1)) >> 1;

  cout << res << endl;

}

int main() {

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i)
    solve();

  return 0;
}
