using namespace std;
#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << (x) << endl

int dp[55][260];

int go(string &s, int i, char a) {
  if (a == ('z' + 1)) return 0;
  if (s.size() == i) return 'z' - a + 1;

  if (dp[i][a] != -1)
    return dp[i][a];

  int ans = 30;
  if (s[i] == a) {
    ans = min(ans, go(s, i + 1, a + 1));
  } else {
    ans = min(ans, go(s, i, a + 1) + 1);
    ans = min(ans, go(s, i + 1, a));
  }
  return dp[i][a] = ans;
}

int main() {
  string s;
  cin >> s;
  memset(dp, -1, sizeof dp);
  cout << go(s, 0, 'a') << endl;
  return 0;
}
