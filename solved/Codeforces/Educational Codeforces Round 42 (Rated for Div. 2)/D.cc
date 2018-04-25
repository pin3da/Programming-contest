#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif


void solve() {
  int n; cin >> n;
  map<long long, int> f, seen;
  for (int i = 0; i < n; i++) {
    long long t; cin >> t;
    f[t]++;
    seen[t] = i;
    while (f.count(t) && f[t] > 1) {
      f[2 * t] += f[t] / 2;
      f[t] = f[t] & 1;
      seen[2 * t] = i;
      t = 2 * t;
    }
  }

  vector<pair<long long, long long>> ans;

  for (auto it : f) {
    if (it.second == 1) {
      ans.emplace_back(seen[it.first], it.first);
    }
  }

  sort(ans.begin(), ans.end());

  for (int i = 1; i < int(ans.size()); i++) {
    assert(ans[i].first != ans[i - 1].first);
  }

  cout << ans.size() << endl;
  for (auto it : ans) {
    cout << it.second << " ";
  }
  cout << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
  solve();
  return 0;
}

