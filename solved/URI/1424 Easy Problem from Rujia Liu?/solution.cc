#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void solve(int n) {
  unordered_map<int, vector<int>> p;
  int q; cin >> q;
  int t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    p[t].push_back(i);
  }

  int v, k;
  while (q--) {
    cin >> k >> v;
    if (p.count(v) && p[v].size() >= k) {
      cout << p[v][k - 1] + 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) solve(n);
  return 0;
}
