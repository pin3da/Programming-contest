#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct entry {
  int id, a, b;
  entry() {}
  entry(int x, int y, int z) : id(x), a(y), b(z) {}
};

void solve() {
  int n; cin >> n;
  vector<vector<entry>> ans;
  int m = n;
  if (n & 1) {
    int a = n, b = n - 1, c = n - 2;
    for (int j = 0; j < n; ++j) {
      int k = (j + 1) % n;
      int l = (j + 2) % n;
      vector<entry> tmp;
      tmp.emplace_back(a, j + 1, k + 1);
      tmp.emplace_back(b, j + 1, l + 1);
      tmp.emplace_back(c, k + 1, l + 1);
      ans.push_back(tmp);
    }
    m -= 3;
  }

  for (int i = 0; i < m; i += 2) {
    for (int j = 0; j < n; j++) {
      int k = (j + 1) % n;
      vector<entry> tmp;
      tmp.emplace_back(i + 1, j + 1, k + 1);
      tmp.emplace_back(i + 2, j + 1, k + 1);
      ans.push_back(tmp);
    }
  }

  cout << ans.size() << endl;
  for (auto &i : ans) {
    cout << i.size() << endl;
    for (auto &it : i) {
      cout << it.id << " " << it.a << " " << it.b << endl;
    }
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int tc; cin >> tc;
  while(tc--) solve();
  return 0;
}
