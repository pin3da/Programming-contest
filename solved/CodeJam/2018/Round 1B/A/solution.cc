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

struct state {
  int dist;
  int value;
  state(int a, int b) : dist(a), value(b) {}
  bool operator < (const state &o) const {
    if (dist == o.dist) return value < o.value;
    return dist < o.dist;
  }
};

const int inf = 1e8;
int nxt_missing(set<int> &good, int cur) {
  auto it = good.lower_bound(cur);
  if (it == good.end()) return inf;
  return *it - cur;
}

void solve() {
  long long l; cin >> l;
  int n; cin >> n;
  vector<long long> a(n);
  read(a);
  long long total = accumulate(a.begin(), a.end(), 0LL);
  long long missing = l - total;
  vector<long long> frec(l);
  set<int> good;
  for (long long i = 0; i <= l; i++) {
    if ( (((i * 1000) / l) % 10) >= 5 ) {
      good.insert(i);
    }
  }

  multiset<state> all;
  for (int i = 0; i < missing; i++) {
    all.insert(state(nxt_missing(good, 0), 0));
  }

  for (auto it : a) {
    all.insert(state(nxt_missing(good, it), it));
  }

  vector<long long> ans;
  while (all.size() && all.begin()->dist == 0) {
    ans.push_back(all.begin()->value);
    all.erase(all.begin());
  }

  while (missing && all.size()) {
    auto cur = *all.begin();
    if (cur.dist <= missing) {
      missing -= cur.dist;
      ans.push_back(cur.value + cur.dist);
      all.erase(all.begin());
    } else {
      ans.push_back(cur.value + missing);
      all.erase(all.begin());

      break;
    }
  }

  for (auto it : all)
    ans.push_back(it.value);

  long long res = 0;
  for (auto it : ans) {
    res += it * 100 / l;
    res += good.count(it);
  }
  cout << res << endl;
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

