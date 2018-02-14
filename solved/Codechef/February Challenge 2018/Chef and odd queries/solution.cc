#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif


typedef bitset<100001> bs;

void solve() {
  int n; cin >> n;
  vector<vector<int>> start(n + 1), end(n + 1);
  for (int i = 0; i < n; i++) {
    int t; cin >> t; t--;
    start[t].emplace_back(i);
    cin >> t; t--;
    end[t + 1].emplace_back(i);
  }


  bs arr[n + 1];
  for (int i = 0; i <= n; i++) {
    if (i) arr[i] = arr[i - 1];

    for (auto it : start[i])
      arr[i][it] = 1;

    for (auto it : end[i])
      arr[i][it] = 0;
  }

  int q; cin >> q;
  while (q--) {
    bs ans;
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
      int t; cin >> t; t--;
      ans ^= arr[t];
    }
    cout << ans.count() << endl;
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int tc; cin >> tc;
  while (tc--)
    solve();
  return 0;
}

