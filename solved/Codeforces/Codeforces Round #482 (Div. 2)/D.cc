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

vector<int> gen_div(int x) {
  vector<int> ans;
  for (int i = 1; i * i <= x; i++) {
    if (x % i) continue;
    ans.push_back(i);
    if (i != (x / i)) ans.push_back(x / i);
  }
  return ans;
}

struct Solution {

  set<int> data;
  vector<int> cand;

  void add(int x) {
    data.insert(x);
  }

  int query(int x, int k, int s) {
    cand.clear();
    for (auto d : gen_div(x)) {
      for (int i = 1; d * i * k <= s - x; i++) {
        if (data.count(i * d * k))
          cand.push_back(i * d * k);
      }
    }

    sort(cand.begin(), cand.end());
    cand.resize(unique(cand.begin(), cand.end()) - cand.begin());

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

