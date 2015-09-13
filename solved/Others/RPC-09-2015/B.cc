#include<bits/stdc++.h>
using namespace std;

int n, c;

const int MN = 2 * 100001;
int dp[MN][2];
int seen[MN][2];

int go(vector<int> &val, int i, int t) {
  if (i == n)
    return 0;

  if (seen[i][t])
    return dp[i][t];

  int ans;
  if (t) {
    ans = max(go(val, i + 1, 0) + val[i], go(val, i + 1, 1));
  } else {
    ans = max(go(val, i + 1, 1) - (val[i] + c), go(val, i + 1, 0));
  }

  seen[i][t] = true;
  return dp[i][t] = ans;
}

int main() {
  while (cin >> n >> c) {
    vector<int> val(n);
    for (int i = 0; i < n; ++i) {
      cin >> val[i];
    }
    memset(seen, 0, sizeof seen);
    cout << go(val, 0, 0) << endl;
  }
  return 0;
}
