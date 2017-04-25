// http://codeforces.com/contest/686/problem/C

#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
deque<int> a, b;

deque<int> to_seven(int n) {
  deque<int> ans;
  while (n > 0) {
    ans.push_front(n % 7);
    n /= 7;
  }
  if (ans.size() == 0)
    ans.push_front(0);
  return ans;
}

long long dp2[20][3][(1 << 8) + 100];
long long dp[20][3][(1 << 8) + 100];

long long go2(int id, int top, int mask) {
  if (id == b.size())
    return 1;

  if (dp2[id][top][mask] != -1)
    return dp2[id][top][mask];

  int mmax = top ? b[id] : 6;
  long long ans = 0;
  for (int i = 0; i <= mmax; ++i) {
    if ((mask >> i) & 1) continue;
    ans += go2(id + 1, top && i == mmax, mask | (1 << i));
  }
  return dp2[id][top][mask] = ans;
}

long long go(int id, int top, int mask) {
  if (id == a.size())
    return go2(0, 1, mask);

  if (dp[id][top][mask] != -1)
    return dp[id][top][mask];
  int mmax = top ? a[id] : 6;
  long long ans = 0;
  for (int i = 0; i <= mmax; ++i) {
    if ((mask >> i) & 1) continue;
    ans += go(id + 1, top && i == mmax, mask | (1 << i));
  }
  return dp[id][top][mask] = ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    a = to_seven(n - 1);
    b = to_seven(m - 1);
    memset(dp, -1, sizeof dp);
    memset(dp2, -1, sizeof dp2);
    cout << go(0, 1, 0) << endl;
  }
  return 0;
}
