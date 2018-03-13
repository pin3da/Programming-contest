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
  int n, q; read(n, q);

  vector<int> a(n);
  read(a);

  while (q--) {
    int t; cin >> t;
    if (t == 1) {
      int pos, val;
      read(pos, val);
      a[pos - 1] = val;
    } else {
      int l, r;
      read(l, r);

      l--; r--;
      vector<int> tmp(a.begin() + l, a.begin() + r + 1);
      sort(tmp.rbegin(), tmp.rend());
      long long best = 0;

      for (int i = 0; i + 2 < int(tmp.size()); i++) {
        if (tmp[i] < (tmp[i + 1] + tmp[i + 2])) {
          best = max(best, 0LL + tmp[i] + tmp[i + 1] + tmp[i + 2]);
          break;
        }
      }
      cout << best << endl;
    }
  }
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
