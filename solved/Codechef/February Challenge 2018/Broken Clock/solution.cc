#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

const long long mod = 1000000007LL;

long long add(long long a, long long b) {
  a += b;
  if (a >= mod)
    return a - mod;
  return a;
}

long long mult(long long a, long long b) {
  return (a * b) % mod;
}

long long mod_pow(long long b, long long e) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1)
      ans = mult(ans, b);
    b = mult(b, b);
    e >>= 1;
  }
  return ans;
}

long long inverse(long long x) {
  return mod_pow(x, mod - 2);
}

long long dv(long long x, long long y) {
  long long inv = inverse(y);
  return mult(x, inv);
}

map<long long, long long> seen;
long long get(long long b, long long t) {
  if (t == 1) return b;
  if (seen.count(t)) return seen[t];
  if (t & 1) {
    long long l = (t >> 1);
    long long r = t - l;
    long long p1 = get(b, l), p2 = get(b, r);
    long long right = mod - b;
    long long left = mult(2, mult(p1, p2));
    return seen[t] = add(left, right);
  } else {
    long long p1 = get(b, t / 2);
    return seen[t] = add(mult(2, mult(p1, p1)), mod - 1);
  }
}

void solve() {
  long long l, d, t;
  read(l, d, t);

  long long b = dv(d, l);
  seen.clear();
  cout << mult(get(b, t), l) << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int tc; cin >> tc;
  while (tc--)
    solve();
  return 0;
}

