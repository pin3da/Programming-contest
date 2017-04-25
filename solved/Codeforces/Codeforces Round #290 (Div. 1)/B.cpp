// http://codeforces.com/contest/512/problem/B

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int n;
int l[333], c[333];
const int inf = 1000006;
map<pair<int, int>, int> dp;
int go(int i, int g) {
  if (i == n) {
    if (g == 1) return 0;
    return inf;
  }
  pair<int, int> state(i, g);
  if (dp.count(state))
    return dp[state];

  int ans = go(i + 1, __gcd(g, l[i]));
  if (ans != inf)
    ans += c[i];
  return dp[state] = min(ans,go(i + 1, g));

}

int main() { ___
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> l[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  int ans =  go(0, 0);
  if (ans < inf)
    cout << ans << endl;
  else
    cout << -1 << endl;

  return 0;
}
