#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const long long mod = 1e9 + 7;

void solve(vector<long long> &dp) {
  int n;
  cin >> n;
  map<int, int> frec;
  for (int i = 0; i < n; i++) {
    int tmp; cin >> tmp;
    frec[tmp]++;
  }

  long long total = 1;
  for (auto it = frec.rbegin(); it != frec.rend(); it++) {
    if (it->second & 1) {
      long long left = it->second;
      it->second--;
      auto next = it;
      next++;
      assert(next != frec.rend());
      total = (total * next->second) % mod;
      total = (total * left) % mod;
      next->second--;
    }
    assert((it->second & 1) == 0);
    total = (total * dp[it->second]) % mod;
  }

  cout << total << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  vector<long long> f(1000001);
  f[0] = 1;
  f[2] = 1;
  for (long long i = 4; i < (long long)(f.size()); i += 2) {
    f[i] = ((i - 1) * f[i - 2]) % mod;
  }

  int tc;
  cin >> tc;
  while (tc--)
    solve(f);

  return 0;
}
