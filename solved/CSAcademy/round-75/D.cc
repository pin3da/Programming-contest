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
  long long id, c, t;
  car(long long a, long long b, long long z) : id(a), c(b), t(z) {}
  bool operator < (const car &o) const {
    return id > o.id;
  }
};

void solve() {
  int n; cin >> n;
  vector<car> all;
  for (int i = 0; i < n; i++) {
    long long c, t; cin >> c >> t;
    all.emplace_back(i, c, t);
  }
  sort(all.begin(), all.end(), [&](const car &a, const car &b) {
    if (a.t == b.t) {
      return a.id < b.id;
    }
    return a.t < b.t;
  });

  priority_queue<car> station;
  vector<long long> ans(n);

  long long last = all[0].t;
  for (auto c : all) {
    long long cur_time = c.t;
    long long delta = cur_time - last;

    while (station.size() && station.top().c <= delta) {
      ans[station.top().id] = last + station.top().c;
      last = last + station.top().c;
      delta -= station.top().c;
      station.pop();
    }

    if (station.size()) { // take only one
      auto it = station.top(); station.pop();
      it.c -= delta;
      station.push(it);
    }

    station.push(c);
    last = cur_time;
  }

  while (station.size()) {
    auto cur = station.top(); station.pop();
    ans[cur.id] = cur.c + last;
    last += cur.c;
  }

  for (auto it : ans)
    cout << it << endl;
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

