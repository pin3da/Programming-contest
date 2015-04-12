using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

void solve() {
  int n;
  cin >> n;
  if (n == 0) {
    cin >> n;
    cout << 0 << endl;
    return;
  }

  n++;
  char t;
  vector<int> nums(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> t;
    nums[i] += t - '0';
  }
  long long ans = 0, total = nums[0];
  for (int i = 1; i < n; ++i) {
    if (nums[i]) {
      if (total < i) {
        ans += (i - total);
        total = i;
      }
      total += nums[i];
    }
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
  return 0;
}

