// http://codeforces.com/contest/488/problem/B

using namespace std;
#include <bits/stdc++.h>

void solve(int n) {
  vector<int> nums(n);
  for (int i = 0; i < n; ++i)
    cin >> nums[i];

  sort(nums.begin(), nums.end());
  for (int i = 1; i < 501; ++i) {
    for (int j = i; j < 3 * i + 1; ++j) {
      vector<int> cur = {i, j, 4 * i - j, 3 * i};
      sort(cur.begin(), cur.end());
      int  ii = 0, jj = 0;
      vector<int> ans;
      while (jj < cur.size()) {
        if (ii < nums.size() && cur[jj] == nums[ii])
          ++ii;
        else
          ans.push_back(cur[jj]);
        ++jj;
      }
      if (ii == nums.size()) {
        cout << "YES" << endl;
        for (int k = 0; k < ans.size(); ++k) {
          cout << ans[k] << endl;
        }
        return;
      }
    }
  }
  cout << "NO" << endl;
}

int main() {
  int n;
  while (cin >> n)
    solve(n);

  return 0;
}