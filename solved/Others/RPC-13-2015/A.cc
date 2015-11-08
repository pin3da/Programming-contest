using namespace std;
#include <bits/stdc++.h>

bool seen[501][501][2];
bool dp[501][501][2];

bool go(int n, int m, int t) {
  if (n == 1 && m == 1)
    return 0;
    
  if (m == 1)
    return t == 1;
  if (n == 1)
    return t == 0;
    
  if (seen[n][m][t]) 
    return dp[n][m][t];
    
  seen[n][m][t] = true;
    
  if (t) {
    bool pos = false;
    for (int i = 1; i <= (n >> 1); ++i) {
      bool op1 = go(i, m, t ^ 1);
      bool op2 = go(n - i, m , t ^ 1);
      pos |= !op1 && !op2;
    }
    return dp[n][m][t] = pos;
  } else {
    bool pos = false;
    for (int i = 1; i <= (m >> 1); ++i) {
      bool op1 = go(n, i, t ^ 1);
      bool op2 = go(n, m - i, t ^ 1);
      pos |= !op1 && !op2;
    }
    return dp[n][m][t] = pos;
  }
}

void solve() {
  int n, m; cin >> m >> n;
  string line; cin >> line;
  int t = (line[0] == 'H');
  int ans = go(n, m, t);
  if (!ans)
    cout << line << " cannot win" << endl;
  else
    cout << line << " can win" << endl;
}

int main() {
  int n; cin >> n;

  while (n--) {
    solve();
  }
  return 0;
}

