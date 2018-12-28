#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const long long mod = 998244353;

long long solve(string line) {
  int n = line.size();
  long long pref = 0;
  for (int i = 0; i < n && line[i] == line[0]; i++) {
    pref++;
  }
  return pref + 1;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  long long n;
  cin >> n;
  string line;
  cin >> line;

  long long ans = 0;
  if (line[0] != line.back()) {
    ans = solve(line);
    reverse(line.begin(), line.end());
    ans = (ans + solve(line) - 1) % mod;
  } else {
    long long pref = 0;
    for (int i = 0; i < n && line[i] == line[0]; i++) {
      pref++;
    }
    long long suf = 0;
    for (int i = n -1; i >= 0 && line[i] == line[0]; i--) {
      suf++;
    }
    if (pref + suf >= n) { // all equal
      ans = (n * (n + 1)) / 2;
      ans %= mod;
    } else {
      ans = (suf + 1 + (pref * (suf + 1)) % mod) % mod;
    }
  }

  cout << ans << endl;
  return 0;
}
