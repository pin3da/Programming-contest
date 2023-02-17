#include <bits/stdc++.h>

using namespace std;

const int inf = 1000;

void solve() {
  int n, A, B;
  cin >> n >> A >> B;
  string number;
  cin >> number;
  vector<int> digits(n);
  for (int i = 0; i < n; i++) {
    digits[i] = number[i] - '0';
  }
  int dp[n + 1][n + 1][A][B];
  for (int i = 0; i < A; i++) {
    for (int j = 0; j < B; j++) {
      dp[n][n][i][j] = inf;
      dp[n][0][i][j] = inf;
    }
  }
  for (int reds = 1; reds < n; reds++) {
    int blacks = n - reds;
    for (int i = 0; i < A; i++) {
      for (int j = 0; j < B; j++) {
        dp[n][reds][i][j] = inf;
      }
    }
    dp[n][reds][0][0] = abs(reds - blacks);
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int reds = 0; reds < n; reds++) {
      for (int modA = 0; modA < A; modA++) {
        for (int modB = 0; modB < B; modB++) {
          int opt1 = dp[i + 1][reds + 1][((modA * 10) + digits[i]) % A][modB];
          int opt2 = dp[i + 1][reds][modA][((modB * 10) + digits[i]) % B];
          dp[i][reds][modA][modB] = min(opt1, opt2);
        }
      }
    }
  }

  string ans;
  int best = dp[0][0][0][0];
  if (best == inf) {
    cout << -1 << endl;
    return;
  }

  int reds = 0;
  int modA = 0;
  int modB = 0;
  for (int i = 0; i < n; i++) {
    int opt1 = dp[i + 1][reds + 1][((modA * 10) + digits[i]) % A][modB];
    int opt2 = dp[i + 1][reds][modA][((modB * 10) + digits[i]) % B];
    if (opt1 == best) {
      ans.push_back('R');
      reds++;
      modA = ((modA * 10) + digits[i]) % A;
    } else {
      assert(opt2 == best);
      ans.push_back('B');
      modB = ((modB * 10) + digits[i]) % B;
    }
  }

  cout << ans << endl;
}

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}