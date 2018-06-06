#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int win(long long a1, long long l1, long long a2, long long l2) {
  long long x1 = (l1 + a2 - 1) / a2;
  long long x2 = (l2 + a1 - 1) / a1;
  return x2 <= x1;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#endif

  long long a1, l1, a2, l2, c, x, y;
  cin >> a1 >> l1 >> a2 >> l2 >> c >> x >> y;

  int ok = false;
  for (long long i = 0; i <= c; i++) {
    if (win(a1 + i * x, l1 + (c - i) * y, a2, l2)) {
      ok = true;
      break;
    }
  }

  puts(ok ? "1" : "0");

  return 0;
}

