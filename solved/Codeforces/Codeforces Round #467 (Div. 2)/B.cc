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

  long long n, p;
  cin >> p >> n;

  for (long long t = n; t > p; t--) {
    vector<long long> factors;
    long long ans = t;
    for (long long a = 2; a * a <= ans; a++) {
      if ((ans % a) == 0) {
        factors.push_back(a);
        while ((ans % a) == 0) ans /= a;
      }
    }
    if (ans > 1) factors.push_back(ans);

    int prime = true;

    for (auto it : factors) {
      if (it <= p) prime = false;
    }

    if (prime) {
      cout << t << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
