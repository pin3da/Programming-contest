#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
  vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));

  for (int i = s1.size() - 1; i >= 0; i--) {
    for (int j = s2.size() - 1; j >= 0; j--) {
      dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
      if (s1[i] == s2[j]) dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + 1);
    }
  }
  return dp[0][0];
}


int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string s1;
  getline(cin, s1);

  string s2;
  getline(cin, s2);

  int result = commonChild(s1, s2);

  fout << result << "\n";

  fout.close();

  return 0;
}
