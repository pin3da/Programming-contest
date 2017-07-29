#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

void solve() {
  string line;
  getline(cin, line);
  stringstream ss(line);
  vector<int> all;
  int t;
  while (ss >> t) {
    all.push_back(t);
  }
  int n = all.size() - 1;
  int seen = 0;
  set<int> other;
  for (auto i : all) {
    if (!seen && i == n) {
      seen = true;
    } else {
      other.insert(i);
    }
  }
  auto last = *(--other.end());
  cout << last << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  string line;
  getline(cin, line);
  int tc = stoi(line);
  while (tc--) {
    solve();
  }
  return 0;
}
