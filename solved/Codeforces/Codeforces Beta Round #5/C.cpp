// http://codeforces.com/contest/5/problem/C

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
void solve(string &line) {
  vector<int> q(line.size() + 10), dp(line.size() + 10, 0);
  int top = 0;
  for (int i = 0; i < line.size(); ++i) {
    if (line[i] == '(') q[top++] = i;
    else if (top > 0) {
      top--;
      dp[i] = i - q[top] + 1;
      if ((q[top] - 1) >= 0)
        dp[i] += dp[q[top] - 1];
    }
  }

  int best = *max_element(dp.begin(), dp.end());
  int times = best ? count(dp.begin(), dp.end(), best) : 1;
  cout << best << " " << times << endl;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line) solve(line);
  return 0;
}
