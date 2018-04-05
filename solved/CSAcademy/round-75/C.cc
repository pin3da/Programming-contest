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

struct car {
  long long d, v, id;
  car(long long a, long long b, long long c) : d(a), v(b), id(c) {}
  bool operator < (const car &o) const {
    if (d * o.v == o.d * v) {
      return id < o.id;
    }
    return d * o.v < o.d * v;
  }
};

void solve() {
  int n, x, y;
  read(n, x, y);
  vector<car> all, red;
  for (int i = 0; i < n; i++) {
    int d, v; cin >> d >> v;
    all.emplace_back(d, v, i);
    red.emplace_back(d, v - y, i);
  }

  vector<car> ori = all;
  sort(all.begin(), all.end());
  sort(red.begin(), red.end());

  for (int i = 0; i < n; i++) {
    car cur = ori[i];
    int id1 = lower_bound(red.begin(), red.end(), cur) - red.begin();
    cur.v += x;
    int id2 = lower_bound(all.begin(), all.end(), cur) - all.begin();
    debug(id1, id2);
    cout << min(id1, id2) + 1 << endl;
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

