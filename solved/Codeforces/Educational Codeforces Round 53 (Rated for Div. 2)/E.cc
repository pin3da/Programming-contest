#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const long long mod = 998244353;

int k;
long long mp[22];
long long dp[20][(1 << 10) + 1][2][2];
long long dp_ans[20][(1 << 10) + 1][2][2];

typedef long long ll;

pair<ll, ll> go(string &s, int idx, const int mask, int top, int first) {
  if (idx == int(s.size())) return {__builtin_popcount(mask) <= k, 0};
  int mmax = top ? s[idx] - '0' : 9;

 if (dp[idx][mask][top][first] != -1) {
    return {dp[idx][mask][top][first], dp_ans[idx][mask][top][first]};
  }

  long long acc = 0;
  long long acc_ans = 0;
  for (int d = 0; d <= mmax; d++) {
    int nmask = mask;
    if ((d != 0) || first) nmask |= (1 << d);

    auto tmp = go(s, idx + 1, nmask, top && (d == mmax), first || (d != 0));

    auto times = tmp.first % mod;
    long long right = (mp[s.size()-1-idx] * d) % mod;
    right = (right * times) % mod;
    assert(right >= 0);

    acc_ans = (acc_ans + right) % mod;
    acc_ans = (acc_ans + tmp.second) % mod;

    acc += times;
  }

  dp[idx][mask][top][first] = acc;
  dp_ans[idx][mask][top][first] = acc_ans % mod;
  return {acc, acc_ans};
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  mp[0] = 1;
  for (int i = 1; i < 22; i++) {
    mp[i] = mp[i-1] * 10LL;
    mp[i] %= mod;
  }

  long long a, b;
  cin >> a >> b >> k;

  string s = to_string(b);
  memset(dp, -1, sizeof dp);
  auto tmp = go(s, 0, 0, true, false);
  long long ans1 = tmp.second % mod;
  if (a) a--;
  s = to_string(a);
  memset(dp, -1, sizeof dp);
  tmp = go(s, 0, 0, true, false);
  cout << (ans1 - tmp.second + mod) % mod << endl;
  return 0;
}
