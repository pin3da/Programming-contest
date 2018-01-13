#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

deque<int> conv(long long b) {
  deque<int> ans;
  while (b) {
    ans.push_front(b % 10);
    b /= 10;
  }
  return ans;
}

deque<int> B, A;
int N;
long long p10[20];

long long dp[(1 << 19) + 100][3][3];
const long long inf = 1e18 + 100;

long long go(int mask, int top, int first) {
  if (mask == 0) return 0;

  if (dp[mask][top][first] != -1)
    return dp[mask][top][first];

  int id = N - __builtin_popcount(mask);
  int mmax = top ? B[id] : 9;
  int start = first ? 0 : 1;

  long long best = -inf;
  for (int i = 0; i < N; i++) {
    if (((mask >> i) & 1) && (A[i] >= start) && (A[i] <= mmax)) {
      long long opt = go(mask ^ (1 << i), top && (A[i] == mmax), first || (A[i] != 0));
      if (opt >= 0){
        opt += p10[__builtin_popcount(mask) - 1] * A[i];
        best = max(best, opt);
      }
    }
  }
  return dp[mask][top][first] = best;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  p10[0] = 1;
  for (int i = 1; i < 20; i++)
    p10[i] = p10[i - 1] * 10LL;

  long long a, b;
  cin >> a >> b;

  B = conv(b);
  A = conv(a);
  N = A.size();
  if (A.size() < B.size()) {
    sort(A.rbegin(), A.rend());
    for (auto i : A)
      cout << i;
    cout << endl;
    return 0;
  } else if (A.size() > B.size()) {
    assert(false);
    return 0;
  }

  int mask = (1 << A.size()) - 1;

  memset(dp, -1, sizeof dp);
  long long ans = go(mask, 1, 0);
  assert(ans > 0);
  cout << ans << endl;

  return 0;
}
