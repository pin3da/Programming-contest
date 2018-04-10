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
  vector<int> a, b;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    if (i & 1) b.push_back(t);
    else a.push_back(t);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  vector<int> cur;
  for (int i = 0; i < n; i++) {
    if (i < int(a.size())) cur.push_back(a[i]);
    if (i < int(b.size())) cur.push_back(b[i]);
  }

  int ans = -1;
  for (int i = 0; i + 1 < int(cur.size()); i++) {
    if (cur[i] > cur[i + 1]) {
      ans = i;
      break;
    }
  }

  if (ans == -1)
    cout << "OK" << endl;
  else
    cout << ans << endl;

}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }
  return 0;
}

