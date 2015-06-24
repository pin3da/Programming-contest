using namespace std;
#include <bits/stdc++.h>

int f(vector<int> &num, long long cap) {
  long long cur = 0;
  int ans = 1;
  for (int i = 0; i < num.size(); ++i) {
    if (num[i] > cap)
      return 1000000;
    if (cur + num[i] <= cap) {
      cur += num[i];
    } else {
      cur = num[i];
      ans++;
    }
  }
  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> nums(n);
  int mmax = 0;
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
    mmax = max(mmax, nums[i]);
  }
  if (m >= n) {
    cout << mmax << endl;
    return;
  }

  long long lo = 0, hi = 1000000000 + 1000;
  while (lo < hi) {
    if (lo + 1 == hi) {
      if (f(nums, lo) > m)
        lo = hi;
      break;
    }
    long long mid = (lo + hi) >> 1;
    if (f(nums, mid) <= m)
      hi = mid;
    else
      lo = mid + 1;
  }
  printf("%lld\n", lo);
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
