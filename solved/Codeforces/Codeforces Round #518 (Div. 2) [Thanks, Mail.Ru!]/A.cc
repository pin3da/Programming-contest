#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  long long n, m, k, l;
  cin >> n >> m >> k >> l;
  long long x = k + l;
  long long a = x / m;
  long long b = -1;
  for (int i = -2; i <= 2; i++) {
    b = a + i;
    if ((b * m >= (k + l)) && (b * m) <= n) {
      break;
    }
    b = -1;
  }
  cout << b << endl;
  return 0;
}
