#include<bits/stdc++.h>

using namespace std;

const int MN = 20;
const int MBEF = 11;

int dp[MN][MBEF][3];

bool go(string &s, int id, int bef, int top) {
  if ((int)s.size() <= id) return true;

  if (dp[id][bef][top] != -1)
    return dp[id][bef][top];

  int mmax = top ? s[id] - '0' : 9;
  for (int i = mmax; i >= 0; --i) {
    if (i >= bef) {
      if (go(s, id + 1, i, top && (i == mmax)))
        return (dp[id][bef][top] = true);
    }
  }
  return (dp[id][bef][top] = false);
}

void solve() {
  string s;
  cin >> s;
  memset(dp, -1, sizeof dp);
  deque<char> ans(s.size(), '0');
  int id = 0, bef = 0, top = true;
  while (id < (int)s.size()) {
    int mmax = top ? s[id] - '0' : 9;
    int seen = false;
    for (int i = mmax; i >= 0; --i) {
      if (i >= bef) {
        if (go(s, id + 1, i, top && (i == mmax))) {
          seen = true;
          ans[id] = i + '0';
          id = id + 1;
          bef = i;
          top = top && (i == mmax);
          break;
        }
      }
    }
    assert(seen);
  }
  while (ans.size() > 1 && ans[0] == '0')
    ans.pop_front();

  for (char i : ans)
    printf("%c", i);

  puts("");
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case #%d: ", i + 1);
    solve();
  }
  return 0;
}
