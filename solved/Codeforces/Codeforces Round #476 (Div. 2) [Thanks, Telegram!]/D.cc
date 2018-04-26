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
  int id;
  long long cap;
  state() {}
  state(int a, long long b) : id(a), cap(b) {}
  bool operator < (const state &o) const {
    return id > o.id;
  }
};

void solve() {
  int w, l;
  cin >> w >> l;

  vector<int> a(w - 1);
  read(a);

  long long inf = accumulate(a.begin(), a.end(), 0LL);

  set<state> q;
  q.insert(state(w - 1, inf + 100));

  for (int i = w - 2; i >= 0; i--) {
    while (q.size() && q.begin()->id > (i + l)) {
      q.erase(q.begin());
    }

    long long cap_out = 0;
    while (a[i] && q.size()) {
      auto nxt = *q.begin();
      if (nxt.cap > a[i]) {
        q.erase(q.begin());
        q.insert(state(nxt.id, nxt.cap - a[i]));
        cap_out += a[i];
        a[i] = 0;
      } else {
        cap_out += nxt.cap;
        a[i] -= nxt.cap;
        q.erase(q.begin());
      }
    }

    if (cap_out)
      q.insert(state(i, cap_out));
  }

  while (q.size() && q.begin()->id >= l)
    q.erase(q.begin());

  long long ans = 0;
  for (auto it : q) {
    ans += it.cap;
  }
  cout << ans << endl;
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

