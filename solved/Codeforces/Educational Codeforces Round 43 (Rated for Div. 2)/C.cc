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

struct interval {
  int b, e, id;
  bool operator < (const interval &o) const {
    if (b == o.b) {
      if (e == o.e) return id < o.id;
      return e > o.e;
    }
    return b < o.b;
  }
};

void solve() {
  int n; cin >> n;
  vector<interval> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].b >> a[i].e;
    a[i].id = i;
  }
  sort(a.begin(), a.end());

  set<pair<int, int>> right;
  for (auto it : a) {
    auto l = right.lower_bound({it.e, -1});
    if (l != right.end()) {
      cout << it.id + 1 << " " << l->second + 1 << endl;
      return;
    }
    right.insert({it.e, it.id});
  }
  cout << "-1 -1" << endl;
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

