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
  vector<int> a(n);
  read(a);

  int q; cin >> q;
  while (q--) {
    char t; cin >> t;
    int l, r; cin >> l >> r;
    l--, r--;
    if (t == '&') {
      int x; cin >> x;
      for (int j = l; j <= r; j++)
        a[j] &= x;

      /*
      for (int j = 0; j < n; j++)
        cerr << a[j] << ' ';
      cerr << endl;
      */
    }
    if (t == '|') {
      int x; cin >> x;
      for (int j = l; j <= r; j++)
        a[j] |= x;

      /*
      for (int j = 0; j < n; j++)
        cerr << a[j] << ' ';
      cerr << endl;
      */
    }
    if (t == '?') {
      cout << *(min_element(a.begin() + l, a.begin() + r + 1)) << endl;
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

