#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


long long f(long long x1, long long y1, long long x2, long long y2) {
  long long x = x1 - x2, y = y1 - y2;
  return x * x + y * y;
}


long long cross(long long x1, long long y1, long long x2, long long y2) {
  return x1 * y2 - x2 * y1;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  vector<long long> x(3), y(3);

  for (long long i = 0; i < 3; i++) {
    cin >> x[i] >> y[i];
  }

  long long ab = f(x[0], y[0], x[1], y[1]);
  long long bc = f(x[2], y[2], x[1], y[1]);

  if (cross(x[1] - x[0], y[1] - y[0], x[2] - x[0], y[2] - y[0]) == 0) {
    puts("No");
  } else {
    puts((ab == bc) ? "Yes" : "No");
  }

  return 0;
}
