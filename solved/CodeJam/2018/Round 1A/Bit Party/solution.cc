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

typedef long long int64;

struct cachier {
  int64 m, s, p;
  cachier() {}
  void read() {
    cin >> m >> s >> p;
  }
};
bool test(int64 r, int64 b, vector<cachier> &all, int64 m_time) {
  deque<int64> items_cachier;
  for (auto it : all) {
    int64 items = (m_time - it.p) / it.s;
    items = max(0LL, min(items, it.m));
    if (items) items_cachier.emplace_back(items);
  }

  sort(items_cachier.begin(), items_cachier.end());

  while (r && b && items_cachier.size()) {
    b -= items_cachier.back(); items_cachier.pop_back();
    if (b < 0) b = 0;
    r--;
  }
  return b == 0;
}

void solve() {
  int64 r, b, c;
  read(r, b, c);
  vector<cachier> all(c);
  for (auto &it : all) it.read();

  if (test(r, b, all, 1)) {
    cout << 1 << endl;
    return;
  }

  int64 hi = 1;
  while (test(r, b, all, hi) == false) {
    hi <<= 1;
  }

  int64 lo = 1;
  while (lo < hi) {
    int64 mid = (lo + hi) >> 1;
    if (test(r, b, all, mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << lo << endl;
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

