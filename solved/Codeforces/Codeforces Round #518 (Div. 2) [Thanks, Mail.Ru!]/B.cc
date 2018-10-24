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

  long long b;
  cin >> b;

  long long ans = 0;
  for (long long i = 1; i * i <= b; i++) {
    if ((b % i) == 0) {
      ans++;
      if ((b / i) != i) ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
