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

long long base;

struct st {
  long long h, d;
  st() {}
  bool operator < (const st &o) const {
    return (h * base - d) > (o.h * base - o.d);
  }
};

long long only_b(vector<st> all, int b) {
  int n = all.size();
  sort(all.begin(), all.end());
  for (int i = 0; i < n && b; i++) {
    all[i].d = max(all[i].d, all[i].h);
    b--;
  }
  long long total = 0;
  for (auto it : all) {
    total += it.d;
  }
  return total;
}

void solve() {
  int n, a, b;
  read(n, a, b);
  int B = b;
  base = 1 << a;
  vector<st> all(n);
  for (auto &i : all) {
    cin >> i.h >> i.d;
  }
  sort(all.begin(), all.end());
  if (b) {
    all[0].d = all[0].h * base;
    b--;
  }

  for (int i = 1; i < n && b; i++) {
    all[i].d = max(all[i].d, all[i].h);
    b--;
  }
  long long total = 0;
  for (auto it : all) {
    total += it.d;
  }
  cout << max(only_b(all, B), total) << endl;
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

