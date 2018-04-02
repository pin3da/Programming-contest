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

int p, a, b, c, d;

double price(int k) {
  return p * (sin(a * k + b) + cos(c * k + d) + 2);
}

void solve() {
  int n;
  read(p, a, b, c, d, n);

  double best = price(1), ans = 0;
  for (int i = 2; i <= n; i++) {
    double cur = price(i);
    if (best > cur) {
      ans = max(ans, best - cur);
    }
    best = max(best, cur);
  }
  cout << fixed << setprecision(8);
  cout << ans << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  solve();
  return 0;
}

