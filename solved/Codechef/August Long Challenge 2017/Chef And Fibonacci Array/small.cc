#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const long long mod = 1000000007LL;

set<vector<int>> seen;

void bfs(vector<int> a) {
  int n = a.size();
  seen.insert(a);
  for (int i = 0; i + 1 < n; i++) {
    if (a[i] > 0 && a[i + 1] > 0) {
      vector<int> next = a;
      if (i + 2 < n)
        next[i + 2]++;
      else
        next.push_back(1);
      next[i]--;
      next[i + 1]--;
      if (seen.count(next) == 0)
        bfs(next);
    }
  }
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  seen.clear();
  bfs(a);
  cout << seen.size() << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int tc; cin >> tc;
  while (tc--) solve();
  return 0;
}
