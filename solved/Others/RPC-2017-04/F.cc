#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl

char f(char x, int inc) {
  if (x + inc > 'z') {
    int nc = 'z' - x + 1;
    return char('a' + (inc - nc));
  }
  return char(x + inc);
}

int n, inc;
string s;

int memo[1005][125];
int solve(int idx, char last) {
  if (memo[idx][last] != -1) return memo[idx][last];
  if (idx == s.size()) return 1;
  int ans = max(0, solve(idx + 1, last));
  if (s[idx] >= last) {
    ans = max(ans, solve(idx + 1, f(s[idx], inc)) + 1);
  }
  return memo[idx][last] = ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    cin >> s >> inc;
    int ans = 0;
    memset(memo, -1, sizeof memo);
    for (int i = 0; i < s.size(); i++) {
      ans = max(ans, solve(i + 1, f(s[i], inc)));
    }
    cout << ans << endl;
  }
  return 0;
}
