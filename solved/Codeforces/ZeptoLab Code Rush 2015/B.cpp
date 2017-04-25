// http://codeforces.com/contest/526/problem/B

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int n, ans;
int nums[4444];

int solve (int node, int level) {
  if (level == n)
    return 0;

  int r = solve(node * 2, level + 1) + nums[node * 2 - 2];
  int l = solve(node * 2 + 1, level + 1) + nums[node * 2 - 1];
  int k = max(r, l);
  ans += k - r;
  ans += k - l;
  return k;
}

int main() { ___
  cin >> n;
  int top = (1 << (n + 1)) - 2;
  memset(nums, 0, sizeof nums);
  for (int i = 0; i < top; ++i) {
    cin >> nums[i];
  }

  ans = 0;
  solve(1, 0);
  cout << ans << endl;

  return 0;
}
