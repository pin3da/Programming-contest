using namespace std;
#include <bits/stdc++.h>

const int inf = 1 << 30;

const int MN = 111;

int dp[MN][MN];
bool seen[MN][MN];

int go(const vector<int> &nums, int i, int j) {
  if (i > j)
    return 0;

  if (i == j)
    return nums[i];

  if (seen[i][j])
    return dp[i][j];

  seen[i][j] = true;

  int accum = 0;
  int best = -inf;
  for (int k = i; k <= j; ++k) {
    accum += nums[k];
    best = max(best, accum - go(nums, k + 1, j));
  }

  accum = 0;
  for (int k = j; k >=  i; --k) {
    accum += nums[k];
    best = max(best, accum - go(nums, i, k - 1));
  }

  return dp[i][j] = best;

}


void solve() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  memset(seen, 0, sizeof seen);
  printf("%d\n", go(nums, 0, n - 1));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
