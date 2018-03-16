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

struct fract {
  long long p, q;
  fract (long long a, long long b) {
    long long g = __gcd(a,b);
    p = a / g;
    q = b / g;
  }
  bool operator < (const fract &o) const {
    return p * o.q < o.p * q;
  }
};

const int MN = 1e6 + 1;
long long sieve[MN];

void solve() {
  int l, r;
  cin >> l >> r;
  vector<fract> cur;
  for (int i = l; i <= r; i++)
    cur.emplace_back(sieve[i], i);
  cout << min_element(cur.begin(), cur.end())->q << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  for (int i = 1; i < MN; i++) {
    for (int j = i + i; j < MN; j += i) {
      sieve[j] += i;
    }
  }
  solve();
  return 0;
}

