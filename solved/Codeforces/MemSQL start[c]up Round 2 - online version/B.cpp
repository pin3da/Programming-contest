// http://codeforces.com/contest/335/problem/B

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 2600 + 10;
int dp[MN][MN];

int go(string &line, int i, int j) {
  if (i > j) return 0;
  if (i == j) return 1;

  if (dp[i][j] != -1)
    return dp[i][j];

  int best = max(go(line, i + 1, j), go(line, i, j - 1));
  if (line[i] == line[j])
    best = max(best, go(line, i + 1, j - 1) + 2);
  return dp[i][j] = best;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line) {
    if (line.size() > 2600) {
      vector<int> frec(26);
      for (auto &i : line)
        frec[i - 'a']++;

      for (int i = 0; i < 26; ++i) {
        if (frec[i] > 100) {
          cout << string(100, i + 'a') << endl;
          break;
        }
      }
    } else {
      memset(dp, -1, sizeof dp);
      int tar = min(go(line, 0, line.size() - 1), 100);

      int i = 0,
          j = line.size() - 1,
          l = 0,
          r = tar - 1;


      string ans(tar, 'a');

      while (i <= j && tar > 0) {
        if (tar == 1) {
          assert(i <= j);
          ans[l++] = line[i];
          break;
        }

        if (line[i] == line[j]) {
          ans[l++] = line[i];
          ans[r--] = line[j];
          i++; j--;
          tar -= 2;
          continue;
        }

        if (dp[i][j] == dp[i + 1][j])
          i++;
        else
          j--;
      }

      cout << ans << endl;
    }
  }
  return 0;
}
