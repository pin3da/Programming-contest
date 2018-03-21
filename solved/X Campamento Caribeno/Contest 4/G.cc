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

int S;

typedef long long T;

const T mod = 1e9 + 7;

T f(long long pos, int k) {
  T ans = 0;
  while (k >= 0) {
    if (pos >= (1 << k)) {
      T id = pos / (1LL << k);
      T times = 0;
      if (id & 1) {
        times += (pos % (1 << k)) + 1;
      }
      times += (id / 2) * (1LL << k);
      times %= mod;
      ans += times * (1LL << (S - 1 - k));
      ans %= mod;
    }
    k--;
  }
  return ans;
}

void solve() {
  cin >> S;
  int q; cin >> q;
  while (q--) {
    int l, r; cin >> l >> r;

    T ans = f(r, S - 1);
    if (l) ans = (ans - f(l - 1, S - 1) + mod) % mod;
    cout << (long long)(ans) << endl;
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

