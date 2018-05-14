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

struct Solution {

  vector<int> data;

  void add(int x) {
    data.push_back(x);
  }

  int query(int x, int k, int s) {
    vector<int> cand;

    for (auto v : data) {
      if (((__gcd(v, x) % k) == 0) && (v + x) <= s)
        cand.push_back(v);
    }

    if (cand.size() == 0)
      return -1;

    int best = cand[0];
    for (auto i : cand) {
      if ((i ^ x) > (best ^ x))
        best = i;
    }
    return best;
  }
};

void solve() {
  int q; cin >> q;

  Solution data;

  while (q--) {
    int t; cin >> t;
    if (t == 1) {
      int u; cin >> u;
      data.add(u);
    }
    if (t == 2) {
      int x, k, s;
      cin >> x >> k >> s;
      cout << data.query(x, k, s) << endl;
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

