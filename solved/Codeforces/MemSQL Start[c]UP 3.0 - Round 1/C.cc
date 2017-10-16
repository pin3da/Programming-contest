#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

typedef pair<long long, long long> state;

state dp[55][2];
bool seen[55][2];

state go(vector<int> &a, int i, int t) {
  if (i + 1 == (int)a.size()) {
    if (t == 0) return {a[i], 0};
    return {0, a[i]};
  }
  if (seen[i][t]) return dp[i][t];
  state ans;
  if (t == 0) {
    state op1 = go(a, i + 1, 0); op1.second += a[i];
    state op2 = go(a, i + 1, 1); op2.first += a[i];
    if (op1.first > op2.first)  ans = op1;
    else ans = op2;
  } else {
    state op1 = go(a, i + 1, 1); op1.first += a[i];
    state op2 = go(a, i + 1, 0); op2.second += a[i];
    if (op1.second > op2.second)  ans = op1;
    else ans = op2;
  }
  seen[i][t] = true;
  return dp[i][t] = ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<int> all(n);
  for (auto &i : all) cin >> i;
  memset(seen, 0, sizeof seen);
  state ans = go(all, 0, 1);
  cout << ans.first << ' ' << ans.second << endl;
  return 0;
}
