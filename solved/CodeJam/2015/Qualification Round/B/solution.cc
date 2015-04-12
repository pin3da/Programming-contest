using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int MN = 1111;
int dp[MN][MN];

int go(vector<int> &nums, int idx, int normal) {
  if (idx == nums.size())
    return normal;

  if (dp[idx][normal] != -1)
    return dp[idx][normal];

  int best = go(nums, idx + 1, max(normal, nums[idx])); // Don't split.

  for (int i = 2; i * i <= nums[idx]; i++) {
    int t = (nums[idx] + i - 1) / i;
    best = min(best, go(nums, idx + 1, max(normal, t)) + i - 1);
    /*
     *D(go(nums, idx + 1, max(normal, t)) + i - 1);
     *D(t);
     *D(nums[idx]);
     *D(t);
     */
  }

  return dp[idx][normal] = best;
}


void solve() {
  int d, t;
  cin >> d;
  vector<int> frec;
  for (int i = 0; i < d; ++i) {
    cin >> t;
    frec.push_back(t);
  }
  memset(dp, -1, sizeof dp);
  int ans = go(frec, 0, 0);

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
  return 0;
}
