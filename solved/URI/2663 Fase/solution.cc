#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  while (cin >> n >> k) {
    vector<int> nums(n);
    for (auto &i : nums) cin >> i;
    sort(nums.rbegin(), nums.rend());
    int ans = k;
    while (ans < n &&  nums[ans] == nums[k - 1]){ans++;}
    cout << ans << endl;
  }
  return 0;
}
