#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

long long mod_pow(long long b, long long e, long long mod) {
  long long a = 1;
  while (e > 0) {
    if (e & 1) a = (a * b) % mod;
    b = (b * b) % mod;
    e >>= 1;
  }
  return a;
}

void solve() {
  int len; cin >> len;
  string moves; cin >> moves;
  string cut; cin >> cut;
  sort(cut.begin(), cut.end());
  int isHorizontal = cut == "LR";
  int ans = 0;
  const long long mod = 1e9 + 7;
  for (char c : moves) {
    if (isHorizontal)
      ans += (c == 'T' || c == 'B');
    else
      ans += (c == 'L' || c == 'R');
  }
  cout << ((mod_pow(2, ans, mod) + 1) % mod) << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int tc; cin >> tc;
  for (int i = 0; i < tc; i++)
    solve();

  return 0;
}
