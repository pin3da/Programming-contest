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


  int n;
  long long k;
  cin >> n >> k;
  vector<long long> fib(n + 1);
  fib[0] = fib[1] = 1;
  for (int i = 2; i <= n; ++i) fib[i] = fib[i - 1] + fib[i - 2];

  int cur = 0;
  while (cur < n) {
    if (k <= fib[n - 1 - cur]) {
      cout << cur + 1 << " ";
      cur++;
    } else {
      cout << cur + 2 << " " << cur + 1 << " ";
      k -= fib[n - 1 - cur];
      cur += 2;
    }
  }
  cout << endl;
  return 0;
}
